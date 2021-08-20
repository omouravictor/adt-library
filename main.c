#include <stdio.h>
#include <stdlib.h>

#include "book.h"
#include "user.h"
#include "borrow.h"
#include "interface.h"

int main()
{
    TBook book;
    TUser user;
    TBorrow borrow;
    TBookModule bookModule;
    TUserModule userModule;
    TBorrowModule borrowModule;
    InitBookModule(&bookModule);
    InitUserModule(&userModule);
    InitBorrowModule(&borrowModule);
    int menuOption;

    do
    {
        system("cls");
        SHOW_MENU();
        printf("Digite uma opcao: ");
        fflush(stdin);
        scanf("%d", &menuOption);
        switch (menuOption)
        {
        case 1:
            SubMenuBookModule(&bookModule, book);
            break;
        case 2:
            SubMenuUserModule(&userModule, user);
            break;
        case 3:
            SubMenuBorrowModule(&borrowModule, &userModule, &bookModule, borrow, user, book);
            break;
        case 4:
            system("cls");
            printf("Programa encerrado.\n");
            break;
        default:
            printf("Digite uma opcao valida!\n");
            system("PAUSE");
            break;
        }
    } while (menuOption != 4);

    return 0;
}