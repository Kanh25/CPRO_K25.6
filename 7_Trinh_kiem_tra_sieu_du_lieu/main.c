#include <stdio.h>
#include "Fileinfo/fileinfo.h"

int main(int argc, char *argv[])
{
    // Kiểm tra tham số dòng lệnh
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    print_file_info(argv[1]);

    return 0;
}