#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source.c> [args...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *src = argv[1];
    const char *out = "a.exe";
    char cmd[512];

    if (snprintf(cmd, sizeof cmd, "clang \"%s\" -o \"%s\"", src, out) >= (int)sizeof cmd || system(cmd) != 0) {
        if (snprintf(cmd, sizeof cmd, "gcc \"%s\" -o \"%s\"", src, out) >= (int)sizeof cmd || system(cmd) != 0) {
            fprintf(stderr, "Compilation failed (tried clang/gcc)\n");
            return EXIT_FAILURE;
        }
    }

    argv[1] = (char *)out;
    int rc = _spawnv(_P_WAIT, out, (const char * const *)&argv[1]);

    if (remove(out) != 0) fprintf(stderr, "Warning: failed to remove %s\n", out);

    return rc == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
}


