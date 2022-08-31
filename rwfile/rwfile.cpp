#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "rwfile.h"

int get_file_size(const char *filename) {
    if (filename == NULL)
        return ERR_ARGS_NULL_RWFILE;

    struct stat st;
    int status;
    status = stat(filename, &st);
    if (status == -1)
        return ERR_FILE_STAT_RWFILE;
    
    return (int) st.st_size;
}

int read_file_text(const char *filename, char *buffer, size_t nSymbols) {
    if (filename == NULL || buffer == NULL)
        return ERR_ARGS_NULL_RWFILE;
    if (nSymbols == 0)
        return 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return ERR_FILE_OPEN_RWFILE;

    int bytes_read = (int) fread(buffer, sizeof(char), nSymbols, file);

    fclose(file);
    return bytes_read;
}
