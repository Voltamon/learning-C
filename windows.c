#include <Windows.h>
#include <stdio.h>

int main() {
  if (!OpenClipboard(NULL)) return 1;

  HANDLE data = GetClipboardData(CF_TEXT);
  if (!data) {
    CloseClipboard();
    return 1;
  }

  char* text = GlobalLock(data);
  if (!text) return 1;

  printf("%s\n", text);
}
