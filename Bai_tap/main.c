#include <stdio.h>
#include "Management/management.h"
#include "Book/book.h"
#include "User/user.h"
#include "Utils/utils.h"

static void bookMenu(Library *lib)
{
    int choice;
    do {
        printf("\n=== MENU SACH ===\n");
        printf("1. Them sach\n");
        printf("2. Sua sach\n");
        printf("3. Xoa sach\n");
        printf("4. Hien thi tat ca sach\n");
        printf("0. Quay lai\n");
        choice = readInt("Chon: ");

        switch (choice) {
        case 1:
            addBook(lib->books, &lib->bookCount);
            break;
        case 2:
            editBook(lib->books, lib->bookCount);
            break;
        case 3:
            deleteBook(lib->books, &lib->bookCount);
            break;
        case 4:
            printAllBooks(lib->books, lib->bookCount);
            break;
        case 0:
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (choice != 0);
}

static void userMenu(Library *lib)
{
    int choice;
    do {
        printf("\n=== MENU NGUOI DUNG ===\n");
        printf("1. Them nguoi dung\n");
        printf("2. Sua nguoi dung\n");
        printf("3. Xoa nguoi dung\n");
        printf("4. Hien thi tat ca nguoi dung\n");
        printf("0. Quay lai\n");
        choice = readInt("Chon: ");

        switch (choice) {
        case 1:
            addUser(lib->users, &lib->userCount);
            break;
        case 2:
            editUser(lib->users, lib->userCount);
            break;
        case 3:
            deleteUser(lib->users, &lib->userCount);
            break;
        case 4:
            printAllUsers(lib->users, lib->userCount);
            break;
        case 0:
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (choice != 0);
}

int main(void)
{
    Library lib;
    initLibrary(&lib);

    int choice;
    do {
        printf("\n========== QUAN LY THU VIEN ==========\n");
        printf("1. Quan ly sach\n");
        printf("2. Quan ly nguoi dung\n");
        printf("3. Muon sach\n");
        printf("4. Tra sach\n");
        printf("5. Tim kiem sach\n");
        printf("6. Hien thi sach con trong kho\n");
        printf("7. Hien thi sach da muon\n");
        printf("8. Hien thi thong tin nguoi dung va sach da muon\n");
        printf("0. Thoat\n");

        choice = readInt("Chon: ");

        switch (choice) {
        case 1:
            bookMenu(&lib);
            break;
        case 2:
            userMenu(&lib);
            break;
        case 3:
            borrowBook(&lib);
            break;
        case 4:
            returnBook(&lib);
            break;
        case 5:
            searchBooks(lib.books, lib.bookCount);
            break;
        case 6:
            printAvailableBooks(lib.books, lib.bookCount);
            break;
        case 7:
            printBorrowedBooks(lib.books, lib.bookCount);
            break;
        case 8:
            showUsersAndBorrowedBooks(&lib);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
