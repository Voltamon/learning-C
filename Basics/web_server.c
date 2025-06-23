#include <errhandlingapi.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winsock.h>
#include <winsock2.h>

#define PORT 8080

DWORD WINAPI handle_client(LPVOID client_socket) {
  SOCKET client = *(SOCKET *)client_socket;
  free(client_socket);

  char request[1024];
  int bytes_received = recv(client, request, sizeof(request) - 1, 0);

  if (bytes_received == SOCKET_ERROR) {
    fprintf(stderr, "Receive failed with error : %d\n", WSAGetLastError());
    fflush(stderr);
    return 1;
  }
  request[bytes_received] = '\0';

  if (memcmp(request, "GET / ", 6) == 0) {
    const char *header = "HTTP/3 200 OK\r\n"
                         "Content-Type: text/html\r\n"
                         "\r\n";
    send(client, header, strlen(header), 0);

    char buffer[256] = "This is from a web server in C\r\n";
    send(client, buffer, strlen(buffer), 0);
  } else {
    const char *bad_request_response = "HTTP/3 400 Bad Request\r\n";
    send(client, bad_request_response, strlen(bad_request_response), 0);
  }

  closesocket(client);
  return 0;
}

int main() {
  volatile bool is_server_running = true;

  WSADATA wsa_data;
  if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
    fprintf(stderr, "WSAStartup failed\n");
    fflush(stderr);
    return 1;
  }

  SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == INVALID_SOCKET) {
    fprintf(stderr, "Failed to create socket\n");
    fflush(stderr);
    WSACleanup();
    return 1;
  }

  struct sockaddr_in server = {.sin_family = AF_INET,
                               .sin_port = htons(PORT),
                               .sin_addr.s_addr = INADDR_ANY};

  if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
    fprintf(stderr, "Bind failed with error : %d\n", WSAGetLastError());
    fflush(stderr);
    goto cleanup;
  }

  if (listen(s, 10) == SOCKET_ERROR) {
    fprintf(stderr, "Listen failed with error : %d\n", WSAGetLastError());
    fflush(stderr);
    goto cleanup;
  }

  while (is_server_running) {
    SOCKET *client = malloc(sizeof(SOCKET));
    if (!client) {
      fprintf(stderr, "Memory allocation failed\n");
      fflush(stderr);
      break;
    }

    *client = accept(s, NULL, NULL);
    if (*client == INVALID_SOCKET) {
      fprintf(stderr, "Acceptefailed\n");
      fflush(stderr);
      continue;
    }

    HANDLE thread = CreateThread(NULL, 0, handle_client, client, 0, NULL);
    if (!thread) {
      fprintf(stderr, "CreateThread failed with error : %d\n", GetLastError());
      fflush(stderr);

      closesocket(*client);
      free(client);
    } else {
      CloseHandle(thread);
    }
  }

cleanup:
  closesocket(s);
  WSACleanup();
}
