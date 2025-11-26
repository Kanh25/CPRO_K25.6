#include <stdio.h>
#include <string.h>
#include "book.h"
#include "../Utils/utils.h"

void addBook(Book books[], int *bookCount)
{
    if (*bookCount >= MAX_BOOKS) {
        printf("Thu vien da day sach!\n");
        return;
    }

    Book *b = &books[*bookCount];

    b->id = readInt("Nhap ID sach: ");
    readLine("Nhap tieu de: ", b->title, TITLE_LEN);
    readLine("Nhap tac gia: ", b->author, AUTHOR_LEN);
    b->isBorrowed = 0;

    (*bookCount)++;
    printf("Them sach thanh cong!\n");
}

int findBookIndexById(Book books[], int bookCount, int id)
{
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

void editBook(Book books[], int bookCount)
{
    int id = readInt("Nhap ID sach muon sua: ");
    int index = findBookIndexById(books, bookCount, id);

    if (index == -1) {
        printf("Khong tim thay sach.\n");
        return;
    }

    Book *b = &books[index];
    printf("Sach hien tai:\n");
    printBook(b);

    readLine("Nhap tieu de moi (de trong neu giu nguyen): ",
             b->title, TITLE_LEN);
    readLine("Nhap tac gia moi (de trong neu giu nguyen): ",
             b->author, AUTHOR_LEN);

    printf("Cap nhat sach thanh cong!\n");
}

void deleteBook(Book books[], int *bookCount)
{
    int id = readInt("Nhap ID sach muon xoa: ");
    int index = findBookIndexById(books, *bookCount, id);

    if (index == -1) {
        printf("Khong tim thay sach.\n");
        return;
    }

    if (books[index].isBorrowed) {
        printf("Sach dang duoc muon, khong the xoa.\n");
        return;
    }

    for (int i = index; i < *bookCount - 1; ++i) {
        books[i] = books[i + 1];
    }
    (*bookCount)--;

    printf("Xoa sach thanh cong!\n");
}

void printBook(const Book *book)
{
    printf("ID: %d | Tieu de: %s | Tac gia: %s | Trang thai: %s\n",
           book->id,
           book->title,
           book->author,
           book->isBorrowed ? "Da muon" : "Con trong kho");
}

void printAllBooks(const Book books[], int bookCount)
{
    if (bookCount == 0) {
        printf("Chua co sach nao.\n");
        return;
    }

    for (int i = 0; i < bookCount; ++i) {
        printBook(&books[i]);
    }
}

void printAvailableBooks(const Book books[], int bookCount)
{
    int found = 0;
    for (int i = 0; i < bookCount; ++i) {
        if (!books[i].isBorrowed) {
            printBook(&books[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong con sach trong kho.\n");
    }
}

void printBorrowedBooks(const Book books[], int bookCount)
{
    int found = 0;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].isBorrowed) {
            printBook(&books[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Chua co sach nao duoc muon.\n");
    }
}

void searchBooks(const Book books[], int bookCount)
{
    int choice;
    printf("1. Tim theo tieu de\n");
    printf("2. Tim theo tac gia\n");
    choice = readInt("Chon: ");

    char keyword[TITLE_LEN];
    if (choice == 1) {
        readLine("Nhap tieu de: ", keyword, TITLE_LEN);
        int found = 0;
        for (int i = 0; i < bookCount; ++i) {
            if (strcmp(books[i].title, keyword) == 0) {
                printBook(&books[i]);
                found = 1;
            }
        }
        if (!found)
            printf("Khong tim thay sach.\n");
    } else if (choice == 2) {
        readLine("Nhap ten tac gia: ", keyword, AUTHOR_LEN);
        int found = 0;
        for (int i = 0; i < bookCount; ++i) {
            if (strcmp(books[i].author, keyword) == 0) {
                printBook(&books[i]);
                found = 1;
            }
        }
        if (!found)
            printf("Khong tim thay sach.\n");
    } else {
        printf("Lua chon khong hop le.\n");
    }
}
