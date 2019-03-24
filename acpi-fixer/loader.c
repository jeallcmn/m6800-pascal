//
// Created by jon on 3/15/19.
//

#include "loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int file_length(const char *name) {
    int fd = open(name, O_RDONLY);

    if( fd >= 0) {
        struct stat st;
        fstat(fd, &st);
        int size = st.st_size;
        close(fd);
        return size;
    } else {
        return -1;
    }
}

char * load_file(const char *name) {

    FILE *f;

    int size = file_length(name);

    if( size > 0 ) {
        f = fopen(name, "rb"); // r for read, b for binary

        if (f != NULL) {
            char *buffer = (char *) malloc(size);
            fread(buffer, size, 1, f);
            fclose(f);

            printf("Loaded file [%s, %d]\n", name, size);
            return buffer;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void write_file(const char *name, void *data, uint32_t len) {
    //printf("Writing to file %s\n", name);
   // int fd = open(name, O_WRONLY);



   // int r = write(fd, data, len);

   // printf("Result = %d", r);
//    close(fd);
}