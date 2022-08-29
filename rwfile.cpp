#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "rwfile.h"

off_t get_file_size(const char *filename) {
    struct stat st;
    int status;
    status = stat(filename, &st);
    if (status == -1) {
        return -1;
    }
    return st.st_size;
}

size_t read_file(const char *filename, char *buffer, size_t nSymbols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return ERR_FILE;
    }
    size_t read_ret = fread(buffer, sizeof(char), nSymbols, file);

    fclose(file);
    return read_ret;
}
