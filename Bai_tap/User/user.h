#ifndef USER_H
#define USER_H

#define MAX_USERS      100
#define MAX_NAME_LEN   100
#define MAX_BORROWED   5

typedef struct {
    int  id;
    char name[MAX_NAME_LEN];
    int  borrowedBookIds[MAX_BORROWED];
    int  borrowedCount;
} User;

void addUser(User users[], int *userCount);
void editUser(User users[], int userCount);
void deleteUser(User users[], int *userCount);

int  findUserIndexById(User users[], int userCount, int id);

void printUser(const User *user);
void printAllUsers(const User users[], int userCount);

#endif
