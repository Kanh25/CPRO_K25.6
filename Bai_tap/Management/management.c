#include <stdio.h>
#include "management.h"
#include "../Utils/utils.h"

void initLibrary(Library *lib)
{
    lib->bookCount = 0;
    lib->userCount = 0;
}

void borrowBook(Library *lib)
{
    int userId  = readInt("Nhap ID nguoi dung: ");
    int userIdx = findUserIndexById(lib->users, lib->userCount, userId);
    if (userIdx == -1) {
        printf("Nguoi dung khong ton tai.\n");
        return;
    }

    int bookId  = readInt("Nhap ID sach: ");
    int bookIdx = findBookIndexById(lib->books, lib->bookCount, bookId);
    if (bookIdx == -1) {
        printf("Sach khong ton tai.\n");
        return;
    }

    User *u = &lib->users[userIdx];
    Book *b = &lib->books[bookIdx];

    if (b->isBorrowed) {
        printf("Sach da duoc muon.\n");
        return;
    }

    if (u->borrowedCount >= MAX_BORROWED) {
        printf("Nguoi dung da muon toi da %d sach.\n", MAX_BORROWED);
        return;
    }

    b->isBorrowed = 1;
    u->borrowedBookIds[u->borrowedCount++] = b->id;

    printf("Muon sach thanh cong!\n");
}

void returnBook(Library *lib)
{
    int userId  = readInt("Nhap ID nguoi dung: ");
    int userIdx = findUserIndexById(lib->users, lib->userCount, userId);
    if (userIdx == -1) {
        printf("Nguoi dung khong ton tai.\n");
        return;
    }

    int bookId  = readInt("Nhap ID sach tra: ");
    int bookIdx = findBookIndexById(lib->books, lib->bookCount, bookId);
    if (bookIdx == -1) {
        printf("Sach khong ton tai.\n");
        return;
    }

    User *u = &lib->users[userIdx];
    Book *b = &lib->books[bookIdx];

    int found = -1;
    for (int i = 0; i < u->borrowedCount; ++i) {
        if (u->borrowedBookIds[i] == bookId) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Nguoi dung nay khong muon cuon sach nay.\n");
        return;
    }

    // xoa bookId khoi danh sach muon
    for (int i = found; i < u->borrowedCount - 1; ++i) {
        u->borrowedBookIds[i] = u->borrowedBookIds[i + 1];
    }
    u->borrowedCount--;

    b->isBorrowed = 0;

    printf("Tra sach thanh cong!\n");
}

void showUsersAndBorrowedBooks(const Library *lib)
{
    if (lib->userCount == 0) {
        printf("Chua co nguoi dung nao.\n");
        return;
    }

    for (int i = 0; i < lib->userCount; ++i) {
        const User *u = &lib->users[i];
        printf("----------------------------------\n");
        printf("Nguoi dung: ");
        printUser(u);

        if (u->borrowedCount == 0) {
            printf("  Khong muon sach nao.\n");
            continue;
        }

        printf("  Cac sach dang muon:\n");
        for (int j = 0; j < u->borrowedCount; ++j) {
            int bookId  = u->borrowedBookIds[j];
            int bookIdx = findBookIndexById((Book *)lib->books,
                                            lib->bookCount, bookId);
            if (bookIdx != -1) {
                printf("    - ");
                printBook(&lib->books[bookIdx]);
            }
        }
    }
}
