#ifndef BORROW_H_INCLUDED
#define BORROW_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "book.h"
#include "user.h"

typedef struct borrow
{
    TBook borrowBook;
    TUser borrowUser;
    TDate bookBorrowDate;
    TDate bookDeliverDate;
    TDate bookReturnDate;
    float penaltyValue;
    int status; // 1 waiting book return 2 Pending penalty payment 3 Finished
} TBorrow;

typedef struct borrowModule
{
    TBorrow borrowList[100];
    int index; // Represents the number of borrows into the borrowList and the next index of borrow to insert
} TBorrowModule;

/* Read the borrow */
void ReadBorrow(TBorrow *borrow, TUser user, TBook book);
/* Shows the borrow attributes */
void PrintBorrow(TBorrow borrow);
/* Starts the index of the BorrowModule */
void InitBorrowModule(TBorrowModule *borrowModule);
/* Insert a borrow ifinto the borrowList of the BorrowModule */
int InsertBorrow(TBorrowModule *borrowModule, TBorrow borrow);
/* Shows all borrows into the borrowList of the BorrowModule */
void PrintAllBorrows(TBorrowModule borrowModule);
/* Returns the index of a borrow inside the borrowList on BorrowModule */
int SearchBorrow(TBorrowModule borrowModule, TBorrow borrow);
/* Updates a borrow inside the borrowList on BorrowModule by the parameter index */
int UpdateBorrow(TBorrowModule *borrowModule, TBorrow updatedBorrow, int indexToUpdate);
/* Deletes a borrow inside the borrowList on BorrowModule by the parameter index */
void DeleteBorrow(TBorrowModule *borrowModule, int indexToDelete);
/* Calc and Returns the borrow deliver date */
TDate GetBookDeliverDate(TDate bookBorrowDate);
/* Calc and Returns the number of days on a year */
int GetQtdDaysOnYear(int day, int month);
/* Calc and Returns the number of penalty days in a year */
int GetQtdPenaltyDays(TDate bookDeliverDate, TDate bookReturnDate);
/* Checks if a borrow can be finished */
int CheckFinishBorrow(TBorrow *borrow);
/* Returns the penalty value of a borrow */
float GetPenaltyValue(int penaltyDays);
/* Execute the payment of a penalty */
void MakePayment(TBorrowModule *borrowModule, TBorrow borrow);

int totalBooksUser(TBorrowModule *borrowModule, TUser user);

#endif