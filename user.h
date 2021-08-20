#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "book.h"

typedef struct address
{
    char street[100];
    int number;
    char district[100];
    char city[100];
    char zipcode[10];
} TAddress;

typedef struct user
{
    char nome[100];
    char CPF[15];
    TAddress address;
    TDate birthDate;
    int userType; // 1 student 2 teacher 3 functionary
    char courseName[100];
    char departmentName[100];
    int noReturnBooksQtd;
    int thereIsPenalty; // 0 nao 1 yes
} TUser;

typedef struct userModule
{
    TUser userList[100];
    int index; // Represents the number of users into the userList and the next index of user to insert
} TUserModule;

/* Read the user */
void ReadUser(TUser *user);
/* Shows the user attributes */
void PrintUser(TUser user);
/* Starts the index of the UserModule */
void InitUserModule(TUserModule *userModule);
/* Insert a user into the userList of the UserModule */
void InsertUser(TUserModule *userModule, TUser user);
/* Shows all users into the userList of the UserModule */
void PrintAllUsers(TUserModule userModule);
/* Returns the index of a user inside the userList on UserModule */
int SearchUser(TUserModule userModule, TUser user);
/* Updates a user inside the userList on UserModule by the parameter index */
void UpdateUser(TUserModule *userModule, TUser updatedUser, int indexToUpdate);
/* Deletes a user inside the userList on UserModule by the parameter index */
void DeleteUser(TUserModule *userModule, int indexToDelete);

#endif