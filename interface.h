#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "book.h"
#include "user.h"
#include "borrow.h"

/* Shows the main menu */
void SHOW_MENU();
/* Shows the sub menu */
void SHOW_SUB_MENU(int moduleOption);
/* Execute the operations of the BookModule */
void SubMenuBookModule(TBookModule *bookModule, TBook book);
/* Execute the operations of the UserModule */
void SubMenuUserModule(TUserModule *userModule, TUser user);
/* Execute the operations of the BorrowModule */
void SubMenuBorrowModule(TBorrowModule *borrowModule, TUserModule *userModule, TBookModule *bookModule, TBorrow borrow, TUser user, TBook book);
/* Returns the index of a borrow inside the borrowList on BorrowModule */
int GetBorrowIndexSearched(TBorrowModule borrowModule, TUser user, TBook book, TBorrow *borrow);
/* Returns the index of a user inside the userList on UserModule */
int GetUserIndexSearched(TUserModule userModule, TUser user);
/* Returns the index of a book inside the bookList on BookModule */
int GetBookIndexSearched(TBookModule bookModule, TBook book);

#endif