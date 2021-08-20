#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

void ReadBook(TBook *book)
{
    printf("Digite o ISBN do livro: ");
    fflush(stdin);
    fgets(book->ISBN, 20, stdin);
    printf("Digite o Titulo do livro: ");
    fflush(stdin);
    fgets(book->tittle, 100, stdin);
    printf("Digite a Editora do livro: ");
    fflush(stdin);
    fgets(book->publisher, 100, stdin);
    printf("Digite o Local de Publicacao do livro: ");
    fflush(stdin);
    fgets(book->publicationLocal, 100, stdin);
    do
    {
        printf("Digite o NUMERO do DIA referente a data de publicacao do livro: ");
        fflush(stdin);
        scanf("%d", &book->publicationDate.day);
        printf("Digite o NUMERO do MES referente a data de publicacao do livro: ");
        fflush(stdin);
        scanf("%d", &book->publicationDate.month);
        printf("Digite o NUMERO do ANO referente a data de publicacao do livro: ");
        fflush(stdin);
        scanf("%d", &book->publicationDate.year);
    } while (dateValidator(book->publicationDate) != 0);
    printf("Digite o Primeiro Autor do livro: ");
    fflush(stdin);
    fgets(book->firstAuthor, 100, stdin);
    printf("Digite o Segundo Autor do livro: ");
    fflush(stdin);
    fgets(book->secondAuthor, 100, stdin);
    printf("Digite o Numero da Edicao do livro: ");
    fflush(stdin);
    scanf("%d", &book->editionNumber);
    printf("Digite a Quantidade Existente deste livro: ");
    fflush(stdin);
    scanf("%d", &book->currentQtdExisting);
    book->currentQtdBorrowed = 0;
}

void PrintBook(TBook book)
{
    printf("ISBN: %s", book.ISBN);
    printf("Titulo: %s", book.tittle);
    printf("Editora: %s", book.publisher);
    printf("Local da publicacao: %s", book.publicationLocal);
    printf("Data da publicacao: %d/%d/%d\n", book.publicationDate.day, book.publicationDate.month, book.publicationDate.year);
    printf("Primeiro autor: %s", book.firstAuthor);
    printf("Segundo autor: %s", book.secondAuthor);
    printf("Numero da edicao: %d\n", book.editionNumber);
    printf("Quantidade existente: %d\n", book.currentQtdExisting);
    printf("Quantidade atual emprestada: %d\n", book.currentQtdBorrowed);
    printf("Quantidade disponivel: %d\n", GetQtdAvailableBooksForBorrow(book));
}

void InitBookModule(TBookModule *bookModule)
{
    bookModule->index = 0;
}

void InsertBook(TBookModule *bookModule, TBook book)
{
    bookModule->bookList[bookModule->index] = book;
    bookModule->index++;
}

void PrintAllBooks(TBookModule bookModule)
{
    for (int i = 0; i < bookModule.index; i++)
    {
        printf("Livro %d\n", i + 1);
        PrintBook(bookModule.bookList[i]);
        printf("\n");
    }
}

int SearchBook(TBookModule bookModule, TBook book)
{
    for (int i = 0; i < bookModule.index; i++)
    {
        if (strcmp(book.ISBN, bookModule.bookList[i].ISBN) == 0)
        {
            return i;
        }
    }
    return -1;
}

void UpdateBook(TBookModule *bookModule, TBook updatedBook, int indexToUpdate)
{
    bookModule->bookList[indexToUpdate] = updatedBook;
}

void DeleteBook(TBookModule *bookModule, int indexToDelete)
{
    for (int i = indexToDelete; i <= bookModule->index - 1; i++)
    {
        bookModule->bookList[i] = bookModule->bookList[i + 1];
    }
    bookModule->index--;
}

int GetQtdAvailableBooksForBorrow(TBook book)
{
    return book.currentQtdExisting - book.currentQtdBorrowed;
}

int dateValidator(TDate date)
{
    if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1)
    {
        printf("Digite uma Data valida!\n");
        system("PAUSE");
        return 1;
    }
    return 0;
}
