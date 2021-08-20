#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "borrow.h"

void ReadBorrow(TBorrow *borrow, TUser user, TBook book)
{
    borrow->borrowUser = user;
    borrow->borrowBook = book;
    do
    {
        printf("Digite o NUMERO do DIA referente a DATA DE REALIZACAO do emprestimo: ");
        fflush(stdin);
        scanf("%d", &borrow->bookBorrowDate.day);
        printf("Digite o NUMERO do MES referente a DATA DE REALIZACAO do emprestimo: ");
        fflush(stdin);
        scanf("%d", &borrow->bookBorrowDate.month);
        printf("Digite o NUMERO do ANO referente a DATA DE REALIZACAO do emprestimo: ");
        fflush(stdin);
        scanf("%d", &borrow->bookBorrowDate.year);
    } while (dateValidator(borrow->bookBorrowDate) != 0);
    borrow->bookDeliverDate = GetBookDeliverDate(borrow->bookBorrowDate);
    borrow->penaltyValue = 0;
    borrow->status = 1;
}

void PrintBorrow(TBorrow borrow)
{
    printf("CPF do usuario: %s", borrow.borrowUser.CPF);
    printf("ISBN do livro: %s", borrow.borrowBook.ISBN);
    printf("Data do emprestimo: %d/%d/%d\n", borrow.bookBorrowDate.day, borrow.bookBorrowDate.month, borrow.bookBorrowDate.year);
    printf("Data limite de entrega: %d/%d/%d\n", borrow.bookDeliverDate.day, borrow.bookDeliverDate.month, borrow.bookDeliverDate.year);
    if (borrow.status != 1)
    {
        printf("Data de devolucao: %d/%d/%d\n", borrow.bookReturnDate.day, borrow.bookReturnDate.month, borrow.bookReturnDate.year);
        if (borrow.status == 2)
        {
            printf("Situacao: PAGAMENTO DE MULTA PENDENTE\n");
        }
        if (borrow.status == 3)
        {
            printf("Situacao: FINALIZADO\n");
        }
    }
    else
    {
        printf("Situacao: AGUARDANDO DEVOLUCAO DE LIVRO\n");
    }
    printf("Valor da Multa: R$ %.2f\n", borrow.penaltyValue);
}

void InitBorrowModule(TBorrowModule *borrowModule)
{
    borrowModule->index = 0;
}

int InsertBorrow(TBorrowModule *borrowModule, TBorrow borrow)
{
    if (GetQtdAvailableBooksForBorrow(borrow.borrowBook) > 1)
    {
        if (borrow.borrowUser.thereIsPenalty == 0)
        {
            if (borrow.borrowUser.userType != 2)
            {
                if (borrow.borrowUser.noReturnBooksQtd < 3)
                {
                    borrowModule->borrowList[borrowModule->index] = borrow;
                    borrowModule->index++;
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (borrow.borrowUser.noReturnBooksQtd < 5)
                {
                    borrowModule->borrowList[borrowModule->index] = borrow;
                    borrowModule->index++;
                    return 1;
                }
                else
                {
                    return -2;
                }
            }
        }
        else
        {
            return -3;
        }
    }
    else
    {
        return -4;
    }
}

void PrintAllBorrows(TBorrowModule borrowModule)
{
    for (int i = 0; i < borrowModule.index; i++)
    {
        printf("Emprestimo %d\n", i + 1);
        PrintBorrow(borrowModule.borrowList[i]);
        printf("\n");
    }
}

int SearchBorrow(TBorrowModule borrowModule, TBorrow borrow)
{
    for (int i = 0; i < borrowModule.index; i++)
    {
        if (strcmp(borrow.borrowUser.CPF, borrowModule.borrowList[i].borrowUser.CPF) == 0 && strcmp(borrow.borrowBook.ISBN, borrowModule.borrowList[i].borrowBook.ISBN) == 0 && borrow.bookBorrowDate.day == borrowModule.borrowList[i].bookBorrowDate.day && borrow.bookBorrowDate.month == borrowModule.borrowList[i].bookBorrowDate.month && borrow.bookBorrowDate.year == borrowModule.borrowList[i].bookBorrowDate.year)
        {
            return i;
        }
    }
    return -1;
}

int UpdateBorrow(TBorrowModule *borrowModule, TBorrow updatedBorrow, int indexToUpdate)
{
    if (GetQtdAvailableBooksForBorrow(updatedBorrow.borrowBook) > 1 || strcmp(updatedBorrow.borrowBook.ISBN, borrowModule->borrowList[indexToUpdate].borrowBook.ISBN) == 0)
    {
        borrowModule->borrowList[indexToUpdate] = updatedBorrow;
        return 1;
    }
    else
    {
        return -1;
    }
}

void DeleteBorrow(TBorrowModule *borrowModule, int indexToDelete)
{
    if (indexToDelete >= 0 && indexToDelete < borrowModule->index)
    {
        for (int i = indexToDelete; i <= borrowModule->index - 1; i++)
        {
            borrowModule->borrowList[i] = borrowModule->borrowList[i + 1];
        }
        borrowModule->index--;
    }
}

TDate GetBookDeliverDate(TDate bookBorrowDate)
{
    TDate bookDeliverDate = bookBorrowDate;
    bookDeliverDate.day += 14;
    if ((bookDeliverDate.month == 1 || bookDeliverDate.month == 3 || bookDeliverDate.month == 5 || bookDeliverDate.month == 7 || bookDeliverDate.month == 8 || bookDeliverDate.month == 10 || bookDeliverDate.month == 12) && bookDeliverDate.day > 31)
    {
        bookDeliverDate.day -= 31;
        bookDeliverDate.month += 1;
    }
    if ((bookDeliverDate.month == 4 || bookDeliverDate.month == 6 || bookDeliverDate.month == 9 || bookDeliverDate.month == 11) && bookDeliverDate.day > 30)
    {
        bookDeliverDate.day -= 30;
        bookDeliverDate.month += 1;
    }
    if (bookDeliverDate.month == 2 && bookDeliverDate.day > 28)
    {
        bookDeliverDate.day -= 28;
        bookDeliverDate.month += 1;
    }
    if (bookDeliverDate.month > 12)
    {
        bookDeliverDate.month -= 12;
        bookDeliverDate.year += 1;
    }
    return bookDeliverDate;
}

int GetQtdDaysOnYear(int day, int month)
{
    int days = day;
    if (month != 1)
    {
        for (int i = 1; i < month; i++)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
            {
                days += 31;
            }
            if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                days += 30;
            }
            if (i == 2)
            {
                days += 28;
            }
        }
    }
    return days;
}

int GetQtdPenaltyDays(TDate bookDeliverDate, TDate bookReturnDate)
{
    int deliverDays, returnDays, penaltyDays = 0;
    deliverDays = GetQtdDaysOnYear(bookDeliverDate.day, bookDeliverDate.month);
    returnDays = GetQtdDaysOnYear(bookReturnDate.day, bookReturnDate.month);
    if (bookDeliverDate.year != bookReturnDate.year)
    {
        for (int i = 0; i < bookReturnDate.year - bookDeliverDate.year; i++)
        {
            penaltyDays += 365;
        }
    }
    penaltyDays -= deliverDays;
    penaltyDays += returnDays;
    return penaltyDays;
}

int CheckFinishBorrow(TBorrow *borrow)
{
    int penaltyDays = GetQtdPenaltyDays(borrow->bookDeliverDate, borrow->bookReturnDate);
    if (penaltyDays <= 0 || borrow->status == 3)
    {
        return 1;
    }
    else
    {
        borrow->penaltyValue = GetPenaltyValue(GetQtdPenaltyDays(borrow->bookDeliverDate, borrow->bookReturnDate));
        return -1;
    }
}

float GetPenaltyValue(int penaltyDays)
{
    return penaltyDays * 2;
}

void MakePayment(TBorrowModule *borrowModule, TBorrow borrow)
{
    borrowModule->borrowList[SearchBorrow(*borrowModule, borrow)].status = 3;
}

int totalBooksUser(TBorrowModule *borrowModule, TUser user)
{
    int qtd = 0;
    for (int i = 0; i < borrowModule->index; i++)
    {
        if (strcmp(borrowModule->borrowList[i].borrowUser.CPF, user.CPF) == 0)
            qtd++;
    }
    return qtd;
}