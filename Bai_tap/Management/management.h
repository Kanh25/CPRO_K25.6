#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "../Book/book.h"
#include "../User/user.h"

typedef struct {
    Book books[MAX_BOOKS];
    int  bookCount;

    User users[MAX_USERS];
    int  userCount;
} Library;

void initLibrary(Library *lib);

void borrowBook(Library *lib);
void returnBook(Library *lib);

void showUsersAndBorrowedBooks(const Library *lib);

#endif
