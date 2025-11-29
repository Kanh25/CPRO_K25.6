#include "fileinfo.h"
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

void print_file_info(const char *path)
{
    struct stat st;

    if (lstat(path, &st) == -1) {
        perror("lstat");
        return;
    }

    printf("File Path: %s\n", path);

    printf("File Type: ");
    if (S_ISREG(st.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(st.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(st.st_mode)) {
        printf("Symbolic Link\n");
    } else {
        printf("Other\n");
    }

    printf("Size: %ld bytes\n", (long)st.st_size);

    char buf[64];
    struct tm *tm_info = localtime(&st.st_mtime);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified: %s\n", buf);
}
