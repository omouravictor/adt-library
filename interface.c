#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

void SHOW_MENU()
{
    printf("1 - Gerenciamento de Livros\n");
    printf("2 - Gerenciamento de Usuarios\n");
    printf("3 - Gerenciamento de Emprestimos\n");
    printf("4 - Encerrar\n");
}

void SHOW_SUB_MENU(int menuOption)
{
    system("cls");
    if (menuOption == 1)
    {
        printf("1 - Cadastrar Livro\n");
        printf("2 - Pesquisar Livro\n");
        printf("3 - Alterar Livro\n");
        printf("4 - Excluir Livro\n");
        printf("5 - Imprimir Todos\n");
        printf("6 - Voltar\n");
    }

    if (menuOption == 2)
    {
        printf("1 - Cadastrar Usuario\n");
        printf("2 - Pesquisar Usuario\n");
        printf("3 - Alterar Usuario\n");
        printf("4 - Excluir Usuario\n");
        printf("5 - Imprimir Todos\n");
        printf("6 - Voltar\n");
    }

    if (menuOption == 3)
    {
        printf("1 - Cadastrar Emprestimo\n");
        printf("2 - Pesquisar Emprestimo\n");
        printf("3 - Alterar Emprestimo\n");
        printf("4 - Excluir Emprestimo\n");
        printf("5 - Imprimir Todos\n");
        printf("6 - Dar baixa em Emprestimo\n");
        printf("7 - Pagar multa de Emprestimo\n");
        printf("8 - Calcular total de livros emprestados para um usuario\n");
        printf("9 - Voltar\n");
    }
}

void SubMenuBookModule(TBookModule *bookModule, TBook book)
{
    int subMenuOption;
    do
    {
        int index;
        SHOW_SUB_MENU(1);
        printf("Digite uma opcao: ");
        fflush(stdin);
        scanf("%d", &subMenuOption);
        switch (subMenuOption)
        {
        case 1:
            system("cls");
            if (bookModule->index < 100)
            {
                printf("### CRIANDO LIVRO ###\n");
                printf("\n");
                ReadBook(&book);
                InsertBook(bookModule, book);
                printf("\n");
                printf("Livro criado com sucesso!\n");
                printf("\n");
            }
            else
            {
                printf("Nao foi possivel criar o livro pois o limite de %d livro[s] cadastrado[s] foi atingido.\n", bookModule->index);
                printf("\n");
            }
            system("PAUSE");
            break;
        case 2:
            system("cls");
            index = GetBookIndexSearched(*bookModule, book);
            if (index != -1)
            {
                printf("Livro encontrado logo abaixo.\n");
                printf("\n");
                PrintBook(bookModule->bookList[index]);
                printf("\n");
            }
            else
            {
                printf("Livro nao encontrado.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");
            index = GetBookIndexSearched(*bookModule, book);
            if (index != -1)
            {
                if (bookModule->bookList[index].currentQtdBorrowed == 0)
                {
                    printf("### ALTERANDO LIVRO ###\n");
                    printf("Informe os novos dados do livro.\n");
                    printf("\n");
                    ReadBook(&book);
                    UpdateBook(bookModule, book, index);
                    printf("\n");
                    printf("Livro alterado com sucesso!\n");
                    printf("\n");
                }
                else
                {
                    printf("Nao e possivel alterar o livro selecionado pois o mesmo esta em condicoes de emprestimo.\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Livro nao encontrado para alteracao.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            printf("Pesquise o livro para ser excluido.\n");
            printf("\n");
            index = GetBookIndexSearched(*bookModule, book);
            if (index != -1)
            {
                DeleteBook(bookModule, index);
                printf("Livro excluido com sucesso!\n");
                printf("\n");
            }
            else
            {
                printf("Livro nao encontrado para exclusao.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 5:
            system("cls");
            if (bookModule->index != 0)
            {
                printf("### MOSTRANDO TODOS OS LIVROS ###\n");
                printf("\n");
                PrintAllBooks(*bookModule);
            }
            else
            {
                printf("Nao existe livros cadastrados ate o momento.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 6:
            break;
        default:
            printf("\n");
            printf("Digite uma opcao valida!\n");
            printf("\n");
            system("PAUSE");
            break;
        }
    } while (subMenuOption != 6);
}

void SubMenuUserModule(TUserModule *userModule, TUser user)
{
    int subMenuOption;
    do
    {
        int index;
        SHOW_SUB_MENU(2);
        printf("Digite uma opcao: ");
        fflush(stdin);
        scanf("%d", &subMenuOption);
        switch (subMenuOption)
        {
        case 1:
            system("cls");
            if (userModule->index < 100)
            {
                printf("### CRIANDO USUARIO ###\n");
                printf("\n");
                ReadUser(&user);
                InsertUser(userModule, user);
                printf("\n");
                printf("Usuario criado com sucesso!\n");
                printf("\n");
            }
            else
            {
                printf("Nao foi possivel criar o usuario pois o limite de %d usuario[s] cadastrado[s] foi atingido.\n", userModule->index);
                printf("\n");
            }
            system("PAUSE");
            break;
        case 2:
            system("cls");
            index = GetUserIndexSearched(*userModule, user);
            if (index != -1)
            {
                printf("Usuario encontrado logo abaixo.\n");
                printf("\n");
                PrintUser(userModule->userList[index]);
                printf("\n");
            }
            else
            {
                printf("Usuario nao encontrado.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");
            index = GetUserIndexSearched(*userModule, user);
            if (index != -1)
            {
                if (userModule->userList[index].noReturnBooksQtd == 0)
                {
                    printf("### ALTERANDO USUARIO ###\n");
                    printf("Informe os novos dados do usuario.\n");
                    printf("\n");
                    ReadUser(&user);
                    UpdateUser(userModule, user, index);
                    printf("\n");
                    printf("Usuario alterado com sucesso!\n");
                    printf("\n");
                }
                else
                {
                    printf("Nao e possivel alterar o usuario selecionado pois o mesmo esta com emprestimos pendentes de devolucao.\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Usuario nao encontrado para alteracao.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            printf("Pesquise o usuario para ser excluido.\n");
            printf("\n");
            index = GetUserIndexSearched(*userModule, user);
            if (index != -1)
            {
                DeleteUser(userModule, index);
                printf("Usuario excluido com sucesso!\n");
                printf("\n");
            }
            else
            {
                printf("Usuario nao encontrado para exclusao.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 5:
            system("cls");
            if (userModule->index != 0)
            {
                printf("### MOSTRANDO TODOS OS USUARIOS ###\n");
                printf("\n");
                PrintAllUsers(*userModule);
            }
            else
            {
                printf("Nao existe usuarios cadastrados ate o momento.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 6:
            break;
        default:
            printf("\n");
            printf("Digite uma opcao valida!\n");
            printf("\n");
            system("PAUSE");
            break;
        }
    } while (subMenuOption != 6);
}

void SubMenuBorrowModule(TBorrowModule *borrowModule, TUserModule *userModule, TBookModule *bookModule, TBorrow borrow, TUser user, TBook book)
{
    int subMenuOption;
    do
    {
        int userIndex, bookIndex, borrowIndex, oldBookIndex, oldBorrowStatus;
        SHOW_SUB_MENU(3);
        printf("Digite uma opcao: ");
        fflush(stdin);
        scanf("%d", &subMenuOption);
        switch (subMenuOption)
        {
        case 1:
            system("cls");
            if (borrowModule->index < 100)
            {
                printf("### CRIANDO EMPRESTIMO ###\n");
                printf("\n");
                userIndex = GetUserIndexSearched(*userModule, user);
                if (userIndex != -1)
                {
                    bookIndex = GetBookIndexSearched(*bookModule, book);
                    if (bookIndex != -1)
                    {
                        ReadBorrow(&borrow, userModule->userList[userIndex], bookModule->bookList[bookIndex]);
                        printf("\n");
                        switch (InsertBorrow(borrowModule, borrow))
                        {
                        case 1:
                            bookModule->bookList[bookIndex].currentQtdBorrowed++;
                            printf("Quantidade[atual] emprestada do Livro atualizada!\n");
                            userModule->userList[userIndex].noReturnBooksQtd++;
                            printf("Quantidade de Livros com o usuario atualizada!\n");
                            printf("\n");
                            printf("Emprestimo realizado com sucesso!\n");
                            printf("\n");
                            break;
                        case -1:
                            printf("Nao foi possivel inserir o emprestimo pois o Aluno ja possui 3 emprestimos pendentes de devolucao.\n");
                            printf("\n");
                            break;
                        case -2:
                            printf("Nao foi possivel inserir o emprestimo pois o Professor ja possui 5 emprestimos pendentes de devolucao.\n");
                            printf("\n");
                            break;
                        case -3:
                            printf("Nao foi possivel inserir o emprestimo pois o usuario possui pagamento de multa pendente.\n");
                            printf("\n");
                            break;
                        case -4:
                            printf("Nao foi possivel inserir o emprestimo devido a quantidade de livros disponiveis do livro selecionado.\n");
                            printf("\n");
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        printf("Livro nao encontrado para emprestimo.\n");
                        printf("\n");
                    }
                }
                else
                {
                    printf("Usuario nao encontrado para emprestimo.\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Nao foi possivel criar o emprestimo pois o limite de %d emprestimo[s] cadastrado[s] foi atingido.\n", borrowModule->index);
                printf("\n");
            }
            system("PAUSE");
            break;
        case 2:
            system("cls");
            borrowIndex = GetBorrowIndexSearched(*borrowModule, user, book, &borrow);
            if (borrowIndex != -1)
            {
                printf("Emprestimo encontrado logo abaixo.\n");
                printf("\n");
                PrintBorrow(borrowModule->borrowList[borrowIndex]);
                printf("\n");
            }
            else
            {
                printf("Emprestimo nao encontrado.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");
            borrowIndex = GetBorrowIndexSearched(*borrowModule, user, book, &borrow);
            if (borrowIndex != -1)
            {
                printf("####### ALTERANDO EMPRESTIMO #######\n");
                printf("Informe os novos dados do emprestimo\n");
                printf("\n");
                oldBookIndex = SearchBook(*bookModule, borrow.borrowBook);
                oldBorrowStatus = borrowModule->borrowList[borrowIndex].status;
                userIndex = GetUserIndexSearched(*userModule, user);
                if (userIndex != -1)
                {
                    bookIndex = GetBookIndexSearched(*bookModule, book);
                    if (bookIndex != -1)
                    {
                        ReadBorrow(&borrow, userModule->userList[userIndex], bookModule->bookList[bookIndex]);
                        printf("\n");
                        switch (UpdateBorrow(borrowModule, borrow, borrowIndex))
                        {
                        case 1:
                            bookModule->bookList[bookIndex].currentQtdBorrowed++;
                            printf("Quantidade[atual] emprestada do Livro selecionado atualizada!\n");
                            if (oldBorrowStatus == 1)
                            {
                                bookModule->bookList[oldBookIndex].currentQtdBorrowed--;
                                printf("Quantidade[atual] emprestada do Livro antigo atualizada!\n");
                            }
                            if (oldBorrowStatus == 2)
                            {
                                userModule->userList[userIndex].noReturnBooksQtd++;
                                printf("Quantidade de Livros com o usuario atualizada!\n");
                                userModule->userList[userIndex].thereIsPenalty = 0;
                                printf("Multa antiga do usuario removida!\n");
                                printf("Status do emprestimo alterado para 'AGUARDANDO DEVOLUCAO DE LIVRO'!\n");
                            }
                            if (oldBorrowStatus == 3)
                            {
                                userModule->userList[userIndex].noReturnBooksQtd++;
                                printf("Quantidade de Livros com o usuario atualizada!\n");
                                printf("Status do emprestimo alterado para 'AGUARDANDO DEVOLUCAO DE LIVRO'!\n");
                            }
                            printf("\n");
                            printf("Emprestimo alterado com sucesso!\n");
                            printf("\n");
                            break;
                        case -1:
                            printf("Nao foi possivel alterar o emprestimo devido a quantidade de livros disponiveis do livro selecionado.\n");
                            printf("\n");
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        printf("Livro nao encontrado para alteracao do emprestimo.\n");
                        printf("\n");
                    }
                }
                else
                {
                    printf("Usuario nao encontrado para alteracao do emprestimo.\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Emprestimo nao encontrado para alteracao.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            printf("Pesquise o emprestimo para ser excluido.\n");
            printf("\n");
            borrowIndex = GetBorrowIndexSearched(*borrowModule, user, book, &borrow);
            if (borrowIndex != -1)
            {
                DeleteBorrow(borrowModule, borrowIndex);
                printf("Emprestimo excluido com sucesso!\n");
                printf("\n");
            }
            else
            {
                printf("Emprestimo nao encontrado para exclusao.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 5:
            system("cls");
            if (borrowModule->index != 0)
            {
                printf("### MOSTRANDO TODOS OS EMPRESTIMOS ###\n");
                printf("\n");
                PrintAllBorrows(*borrowModule);
            }
            else
            {
                printf("Nao existe emprestimos cadastrados ate o momento.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 6:
            system("cls");
            borrowIndex = GetBorrowIndexSearched(*borrowModule, user, book, &borrow);
            if (borrowIndex != -1)
            {
                if (borrowModule->borrowList[borrowIndex].status == 1)
                {
                    printf("### REALIZANDO DEVOLUCAO ###\n");
                    printf("\n");
                    do
                    {
                        printf("Digite o NUMERO do DIA referente a DATA DE DEVOLUCAO do emprestimo: ");
                        fflush(stdin);
                        scanf("%d", &borrow.bookReturnDate.day);
                        printf("Digite o NUMERO do MES referente a DATA DE DEVOLUCAO do emprestimo: ");
                        fflush(stdin);
                        scanf("%d", &borrow.bookReturnDate.month);
                        printf("Digite o NUMERO do ANO referente a DATA DE DEVOLUCAO do emprestimo: ");
                        fflush(stdin);
                        scanf("%d", &borrow.bookReturnDate.year);
                    } while (dateValidator(borrow.bookReturnDate) != 0);
                    borrowModule->borrowList[borrowIndex].bookReturnDate = borrow.bookReturnDate;
                    printf("\n");
                    bookModule->bookList[SearchBook(*bookModule, borrowModule->borrowList[borrowIndex].borrowBook)].currentQtdBorrowed--;
                    printf("Quantidade[atual] emprestada do Livro atualizada!\n");
                    userModule->userList[SearchUser(*userModule, borrowModule->borrowList[borrowIndex].borrowUser)].noReturnBooksQtd--;
                    printf("Quantidade de Livros com o usuario atualizada!\n");
                    printf("Devolucao realizada!\n");
                    printf("\n");
                    switch (CheckFinishBorrow(&borrowModule->borrowList[borrowIndex]))
                    {
                    case 1:
                        borrowModule->borrowList[borrowIndex].status = 3;
                        printf("Status do emprestimo alterado para 'FINALIZADO'!\n");
                        printf("Emprestimo encerrado com sucesso!\n");
                        printf("\n");
                        break;
                    case -1:
                        borrowModule->borrowList[borrowIndex].status = 2;
                        printf("Status do emprestimo alterado para 'PAGAMENTO DE MULTA PENDENTE'!\n");
                        userModule->userList[SearchUser(*userModule, borrowModule->borrowList[borrowIndex].borrowUser)].thereIsPenalty = 1;
                        printf("Multa registrada ao usuario!\n");
                        printf("\n");
                        printf("Deve ser pago a multa de R$ %.2f para dar baixa neste emprestimo.\n", borrowModule->borrowList[borrowIndex].penaltyValue);
                        printf("Selecione a opcao '7 - Pagar multa de emprestimo' no menu de emprestimos para confirmar o pagamento da multa.\n");
                        printf("\n");
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    printf("Nao foi possivel dar baixa pois o emprestimo informado nao esta em situacao de 'AGUARDANDO DEVOLUCAO DE LIVRO'.\nPesquise-o para checar sua situacao.\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Emprestimo nao encontrado para baixa.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 7:
            system("cls");
            borrowIndex = GetBorrowIndexSearched(*borrowModule, user, book, &borrow);
            if (borrowIndex != -1)
            {
                if (borrowModule->borrowList[borrowIndex].status == 2)
                {
                    MakePayment(borrowModule, borrowModule->borrowList[borrowIndex]);
                    printf("Status do emprestimo alterado para 'FINALIZADO'!\n");
                    userModule->userList[SearchUser(*userModule, borrowModule->borrowList[borrowIndex].borrowUser)].thereIsPenalty = 0;
                    printf("Multa pendente de usuario paga!\n");
                    printf("\n");
                    printf("Pagamento de multa confirmado com sucesso!\n");
                    printf("\n");
                }
                else
                {
                    printf("Nao foi possivel pagar a multa pois o emprestimo informado nao esta em situacao de 'PAGAMENTO DE MULTA PENDENTE'.\nPesquise-o para checar sua situacao.\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Emprestimo nao encontrado para pagar a multa de emprestimo.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 8:
            system("cls");
            userIndex = GetUserIndexSearched(*userModule, user);
            if (userIndex != -1)
            {
                int total = totalBooksUser(borrowModule, userModule->userList[userIndex]);
                printf("Este usuario possui um TOTAL de %d livro[s] JA EMPRESTADO[S] pela biblioteca.\n", total);
                printf("Este usuario possui %d livro[s] PENDENTE[S] DE DEVOLUCAO.\n", userModule->userList[userIndex].noReturnBooksQtd);
                printf("\n");
            }
            else
            {
                printf("Usuario nao encontrado para o calculo de quantidade de livros.\n");
                printf("\n");
            }
            system("PAUSE");
            break;
        case 9:
            break;
        default:
            printf("\n");
            printf("Digite uma opcao valida!\n");
            printf("\n");
            system("PAUSE");
            break;
        }
    } while (subMenuOption != 9);
}

int GetBorrowIndexSearched(TBorrowModule borrowModule, TUser user, TBook book, TBorrow *borrow)
{
    printf("### PESQUISANDO EMPRESTIMO ###\n");
    printf("\n");
    printf("Digite o CPF do usuario [APENAS NUMEROS] para pesquisa: ");
    fflush(stdin);
    fgets(user.CPF, 15, stdin);
    borrow->borrowUser = user;
    printf("Digite o ISBN do livro para pesquisa: ");
    fflush(stdin);
    fgets(book.ISBN, 20, stdin);
    borrow->borrowBook = book;
    do
    {
        printf("Digite o NUMERO do DIA referente a DATA DE REALIZACAO do emprestimo para pesquisa: ");
        fflush(stdin);
        scanf("%d", &borrow->bookBorrowDate.day);
        printf("Digite o NUMERO do MES referente a DATA DE REALIZACAO do emprestimo para pesquisa: ");
        fflush(stdin);
        scanf("%d", &borrow->bookBorrowDate.month);
        printf("Digite o NUMERO do ANO referente a DATA DE REALIZACAO do emprestimo para pesquisa: ");
        fflush(stdin);
        scanf("%d", &borrow->bookBorrowDate.year);
    } while (dateValidator(borrow->bookBorrowDate) != 0);
    printf("\n");
    return SearchBorrow(borrowModule, *borrow);
}

int GetUserIndexSearched(TUserModule userModule, TUser user)
{
    printf("### PESQUISANDO USUARIO ###\n");
    printf("\n");
    printf("Digite o CPF do usuario [APENAS NUMEROS] para pesquisa: ");
    fflush(stdin);
    fgets(user.CPF, 15, stdin);
    printf("\n");
    return SearchUser(userModule, user);
}

int GetBookIndexSearched(TBookModule bookModule, TBook book)
{
    printf("### PESQUISANDO LIVRO ###\n");
    printf("\n");
    printf("Digite o ISBN do livro para pesquisa: ");
    fflush(stdin);
    fgets(book.ISBN, 20, stdin);
    printf("\n");
    return SearchBook(bookModule, book);
}
