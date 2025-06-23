#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 255

typedef struct {
	char** buffer;
	unsigned short int lines;
} FileContent;

FILE* open_file(char* file_name, char* mode) {
	FILE* file = fopen(file_name, mode);

	if (!file)
		fprintf(stderr, "Error opening %s\n", file_name);

	return file;
}

FileContent read_file(char* file_name) {
	FileContent file_content = {calloc(MAX_LINES, sizeof(char*)), 0};
	FILE* file = open_file(file_name, "r");

	if (!file || !file_content.buffer) {
		fclose(file);
		return file_content;
	}

	for(int line = 0; line < MAX_LINES; line++) {
		file_content.buffer[line] = malloc(MAX_LINE_LENGTH * sizeof(char));

		if (!fgets(file_content.buffer[line], MAX_LINE_LENGTH, file)) {
			free(file_content.buffer[line]);
		 	fclose(file);
		 	return file_content;
		}

		file_content.lines++;
	}

	return (FileContent) {NULL, 0};
}

void write_file(char* file_name, FileContent *file_content) {
	FILE* file = open_file(file_name, "w");
	if (!file) return;

	for (int line = 0; line < file_content->lines - 2; line++)
		fprintf(file, "%s", file_content->buffer[line]);

	printf("\e[1;1H\e[2J");
	printf("Successfully wrote %hu lines to %s\n\n", file_content->lines - 2, file_name);

	file_content->lines -= 1;
	fclose(file);
}

void delete_file(char* file_name) {
	if (!remove(file_name))
		printf("Deleted %s successfully\n", file_name);
	else
		fprintf(stderr, "Error deleting %s\n", file_name);
}

void free_buffer(FileContent *file_content) {
	if (file_content->buffer) {
		for (int i = 0; i < file_content->lines; i++)
			free(file_content->buffer[i]);
		free(file_content->buffer);
	}

	file_content->buffer = NULL;
	file_content->lines = 0;
}

bool is_blank_line(char* line) {
	for(size_t i = 0; i < strlen(line); i++)
		if (!isspace((unsigned char)line[i]))
			return false;

	return true;
}

FileContent get_buffer_input() {
	FileContent file_content = {calloc(MAX_LINES, sizeof(char*)), 0};

	if (!file_content.buffer)
		return file_content;

	for (int line = 0, consecutive_blank_lines = 0; line < MAX_LINES; line++) {
		file_content.buffer[line] = malloc(MAX_LINE_LENGTH * sizeof(char));

		if (!fgets(file_content.buffer[line], MAX_LINE_LENGTH, stdin)
		 	|| consecutive_blank_lines >= 3) {

			free(file_content.buffer[line]);
			break;
		}

		if (is_blank_line(file_content.buffer[line]))
			consecutive_blank_lines++;
		else
			consecutive_blank_lines = 0;

		file_content.lines++;
	}

	return file_content;
}

int main() {
	FileContent file_content;
	unsigned short int ch = 0;
	char* file_name = malloc(100 * sizeof(char));

	if (!file_name) {
		fprintf(stderr, "Memory allocation failed\n");
		goto exit;
	}

	while(1) {
		printf("1. Write a file\n");
		printf("2. Read a file\n");
		printf("3. Delete a file\n");
		printf("4. Exit\n");

		printf("Enter your choice : ");
		scanf("%hu", &ch);

		while(getchar() != '\n');

		printf("\e[1;1H\e[2J");
		if (ch < 1 || ch > 4) {
			printf("Invalid Choice\n\n");
			continue;
		}
		if (ch == 4) break;

		printf("Enter file name : ");
		fgets(file_name, 100, stdin);
		file_name[strcspn(file_name, "\n")] = 0;

		printf("\e[1;1H\e[2J");
		switch (ch) {
			case 1:
				file_content = get_buffer_input();
				write_file(file_name, &file_content);

				free_buffer(&file_content);
				break;
			case 2:
				file_content = read_file(file_name);

				if (!file_content.buffer)
					fprintf(stderr, "Error reading %s", file_name);

				for(int i = 0; i < file_content.lines; i++)
					printf("%s", file_content.buffer[i]);

				free_buffer(&file_content);
				break;
			case 3:
				delete_file(file_name);
				break;
		}
	}

	exit:
		free(file_name);
		return 0;
}
