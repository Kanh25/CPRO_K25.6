#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS   100
#define TITLE_LEN   100
#define AUTHOR_LEN  100

typedef struct {
    int  id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int  isBorrowed;   // 0: con trong kho, 1: da muon
} Book;

void addBook(Book books[], int *bookCount);
void editBook(Book books[], int bookCount);
void deleteBook(Book books[], int *bookCount);

int  findBookIndexById(Book books[], int bookCount, int id);

void printBook(const Book *book);
void printAllBooks(const Book books[], int bookCount);
void printAvailableBooks(const Book books[], int bookCount);
void printBorrowedBooks(const Book books[], int bookCount);

void searchBooks(const Book books[], int bookCount);

#endif
