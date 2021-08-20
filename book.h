#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
    int day;
    int month;
    int year;
} TDate;

typedef struct book
{
    char ISBN[20];
    char tittle[100];
    char publisher[100];
    char publicationLocal[100];
    TDate publicationDate;
    char firstAuthor[100];
    char secondAuthor[100];
    int editionNumber;
    int currentQtdExisting;
    int currentQtdBorrowed;
} TBook;

typedef struct bookModule
{
    TBook bookList[100];
    int index; // Represents the number of books into the bookList and the next index of book to insert
} TBookModule;

/* Read the book */
void ReadBook(TBook *book);
/* Shows the book attributes */
void PrintBook(TBook book);
/* Starts the index of the TBookModule */
void InitBookModule(TBookModule *bookModule);
/* Insert a book into the bookList of the TBookModule */
void InsertBook(TBookModule *bookModule, TBook book);
/* Shows all books into the bookList of the TBookModule */
void PrintAllBooks(TBookModule bookModule);
/* Returns the index of a book inside the bookList on TBookModule */
int SearchBook(TBookModule bookModule, TBook book);
/* Updates a book inside the bookList on TBookModule by the parameter index */
void UpdateBook(TBookModule *bookModule, TBook updatedTBook, int indexToUpdate);
/* Deletes a book inside the bookList on TBookModule by the parameter index */
void DeleteBook(TBookModule *bookModule, int indexToDelete);
/* Returns the number of available books for borrow */
int GetQtdAvailableBooksForBorrow(TBook book);
/* Validates the Date of the parameter */
int dateValidator(TDate date);

#endif