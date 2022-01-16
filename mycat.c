/* 
 * File:   mycat.c
 * Author: Cody Register
 * Date: 20220116
 * 
 * C Program that performs the cat function. 
 * Takes a list of files and outputs their content to stdout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int debug = 0;
    if (argc < 1) {
        fprintf(stderr, "Error: Insufficient number of arguments.\n");
        return (EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0) {
            printf("Error opening file %s: %s \n", argv[i], strerror(errno));
        } else {
            char buffer[2048];
            int readCount = 0;
            if (debug > 0) {
                printf("Opening file: %s \n", argv[i]);
            }

            do {
                readCount = read(fd, buffer, sizeof (buffer));
                write(1, buffer, readCount);
            } while (readCount > 0);
            printf("\n");
            close(fd);
        }
    }

    return (EXIT_SUCCESS);
}

