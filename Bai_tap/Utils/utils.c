#include <stdio.h>
#include <string.h>
#include "utils.h"

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Nhap so nguyen hop le: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

void readLine(const char *prompt, char *buffer, int length)
{
    printf("%s", prompt);
    if (fgets(buffer, length, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}
