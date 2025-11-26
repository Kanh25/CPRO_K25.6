#include <stdio.h>
#include "user.h"
#include "../Utils/utils.h"

void addUser(User users[], int *userCount)
{
    if (*userCount >= MAX_USERS) {
        printf("Danh sach nguoi dung da day!\n");
        return;
    }

    User *u = &users[*userCount];
    u->id = readInt("Nhap ID nguoi dung: ");
    readLine("Nhap ten nguoi dung: ", u->name, MAX_NAME_LEN);

    u->borrowedCount = 0;

    (*userCount)++;
    printf("Them nguoi dung thanh cong!\n");
}

int findUserIndexById(User users[], int userCount, int id)
{
    for (int i = 0; i < userCount; ++i) {
        if (users[i].id == id) {
            return i;
        }
    }
    return -1;
}

void editUser(User users[], int userCount)
{
    int id = readInt("Nhap ID nguoi dung muon sua: ");
    int index = findUserIndexById(users, userCount, id);

    if (index == -1) {
        printf("Khong tim thay nguoi dung.\n");
        return;
    }

    User *u = &users[index];
    printf("Nguoi dung hien tai: ");
    printUser(u);

    readLine("Nhap ten moi (de trong neu giu nguyen): ",
             u->name, MAX_NAME_LEN);

    printf("Cap nhat nguoi dung thanh cong!\n");
}

void deleteUser(User users[], int *userCount)
{
    int id = readInt("Nhap ID nguoi dung muon xoa: ");
    int index = findUserIndexById(users, *userCount, id);

    if (index == -1) {
        printf("Khong tim thay nguoi dung.\n");
        return;
    }

    if (users[index].borrowedCount > 0) {
        printf("Nguoi dung dang muon sach, khong the xoa.\n");
        return;
    }

    for (int i = index; i < *userCount - 1; ++i) {
        users[i] = users[i + 1];
    }
    (*userCount)--;

    printf("Xoa nguoi dung thanh cong!\n");
}

void printUser(const User *user)
{
    printf("ID: %d | Ten: %s | So sach dang muon: %d\n",
           user->id, user->name, user->borrowedCount);
}

void printAllUsers(const User users[], int userCount)
{
    if (userCount == 0) {
        printf("Chua co nguoi dung nao.\n");
        return;
    }

    for (int i = 0; i < userCount; ++i) {
        printUser(&users[i]);
    }
}
