#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"

void ReadUser(TUser *user)
{
    printf("Digite o Nome do usuario: ");
    fflush(stdin);
    fgets(user->nome, 100, stdin);
    printf("Digite o CPF do usuario [APENAS NUMEROS]: ");
    fflush(stdin);
    fgets(user->CPF, 15, stdin);
    printf("Digite a Rua de enredeco do usuario: ");
    fflush(stdin);
    fgets(user->address.street, 100, stdin);
    printf("Digite o Numero de enredeco do usuario: ");
    fflush(stdin);
    scanf("%d", &user->address.number);
    printf("Digite o Bairro de enredeco do usuario: ");
    fflush(stdin);
    fgets(user->address.district, 100, stdin);
    printf("Digite a Cidade de enredeco do usuario: ");
    fflush(stdin);
    fgets(user->address.city, 100, stdin);
    printf("Digite o CEP de enredeco do usuario [APENAS NUMEROS]: ");
    fflush(stdin);
    fgets(user->address.zipcode, 10, stdin);
    do
    {
        printf("Digite o NUMERO do DIA referente a data de nascimento do usuario: ");
        fflush(stdin);
        scanf("%d", &user->birthDate.day);
        printf("Digite o NUMERO do MES referente a data de nascimento do usuario: ");
        fflush(stdin);
        scanf("%d", &user->birthDate.month);
        printf("Digite o NUMERO do ANO referente a data de nascimento do usuario: ");
        fflush(stdin);
        scanf("%d", &user->birthDate.year);
    } while (dateValidator(user->birthDate) != 0);
    user->userType = 0;
    do
    {
        printf("1 - Estudante\n");
        printf("2 - Professor\n");
        printf("3 - Funcionario[a]\n");
        printf("Digite o tipo de usuario [NUMERO]: ");
        fflush(stdin);
        scanf("%d", &user->userType);
        switch (user->userType)
        {
        case 1:
            printf("Digite o Nome do Curso: ");
            fflush(stdin);
            fgets(user->courseName, 100, stdin);
            break;
        case 2:
            printf("Digite o Nome do Departamento: ");
            fflush(stdin);
            fgets(user->departmentName, 100, stdin);
            break;
        case 3:
            printf("Digite o Nome do Departamento: ");
            fflush(stdin);
            fgets(user->departmentName, 100, stdin);
            break;
        default:
            printf("Digite uma opcao valida!\n");
            system("PAUSE");
            break;
        }
    } while (user->userType < 1 || user->userType > 3);
    user->noReturnBooksQtd = 0;
    user->thereIsPenalty = 0;
}

void PrintUser(TUser user)
{
    printf("Nome: %s", user.nome);
    printf("CPF: %s", user.CPF);
    printf("Rua: %s", user.address.street);
    printf("Numero: %d\n", user.address.number);
    printf("Bairro: %s", user.address.district);
    printf("Cidade: %s", user.address.city);
    printf("Cep: %s", user.address.zipcode);
    printf("Data de nascimento: %d/%d/%d\n", user.birthDate.day, user.birthDate.month, user.birthDate.year);
    if (user.userType == 1)
    {
        printf("Tipo: Aluno\n");
        printf("Curso: %s", user.courseName);
    }
    if (user.userType == 2)
    {
        printf("Tipo: Professor\n");
        printf("Departamento: %s", user.departmentName);
    }
    if (user.userType == 3)
    {
        printf("Tipo: Funcionario\n");
        printf("Departamento: %s", user.departmentName);
    }
    if (user.thereIsPenalty == 0)
    {
        printf("Multa pendente: NAO\n");
    }
    else
    {
        printf("Multa pendente: SIM\n");
    }
    printf("Qtd de livros sem devolucao: %d\n", user.noReturnBooksQtd);
}

void InitUserModule(TUserModule *userModule)
{
    userModule->index = 0;
}

void InsertUser(TUserModule *userModule, TUser user)
{
    userModule->userList[userModule->index] = user;
    userModule->index++;
}

void PrintAllUsers(TUserModule userModule)
{
    for (int i = 0; i < userModule.index; i++)
    {
        printf("Usuario %d\n", i + 1);
        PrintUser(userModule.userList[i]);
        printf("\n");
    }
}

int SearchUser(TUserModule userModule, TUser user)
{
    for (int i = 0; i < userModule.index; i++)
    {
        if (strcmp(user.CPF, userModule.userList[i].CPF) == 0)
        {
            return i;
        }
    }
    return -1;
}

void UpdateUser(TUserModule *userModule, TUser updatedUser, int indexToUpdate)
{
    userModule->userList[indexToUpdate] = updatedUser;
}

void DeleteUser(TUserModule *userModule, int indexToDelete)
{
    for (int i = indexToDelete; i <= userModule->index - 1; i++)
    {
        userModule->userList[i] = userModule->userList[i + 1];
    }
    userModule->index--;
}