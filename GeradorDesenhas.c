#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int age;
    char phone[MAX_PHONE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void addUser(User users[], int *numUsers) {
    if (*numUsers < MAX_USERS) {
        printf("Digite o nome do usuário: ");
        scanf("%s", users[*numUsers].name);
        printf("Digite o email do usuário: ");
        scanf("%s", users[*numUsers].email);
        printf("Digite a idade do usuário: ");
        scanf("%d", &users[*numUsers].age);
        printf("Digite o telefone do usuário: ");
        scanf("%s", users[*numUsers].phone);
        printf("Usuário cadastrado com sucesso!\n");
        (*numUsers)++;
    } else {
        printf("Limite máximo de usuários alcançado!\n");
    }
}

void viewUsers(User users[], int numUsers) {
    printf("Usuários cadastrados:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%d. Nome: %s | Email: %s | Idade: %d | Telefone: %s\n", i+1, users[i].name, users[i].email, users[i].age, users[i].phone);
    }
}

void editUser(User users[], int numUsers) {
    int index;
    printf("Digite o número do usuário que deseja editar: ");
    scanf("%d", &index);
    index--; // Ajuste para o índice do array
    if (index >= 0 && index < numUsers) {
        printf("Digite o novo nome do usuário: ");
        scanf("%s", users[index].name); // Corrigido: era scanf("%s", &users[index].name);
        printf("Digite o novo email do usuário: ");
        scanf("%s", users[index].email); // Corrigido: era scanf("%s", &users[index].email);
        printf("Digite a nova idade do usuário: ");
        scanf("%d", &users[index].age);
        printf("Digite o novo telefone do usuário: ");
        scanf("%s", users[index].phone); // Corrigido: era scanf("%s", &users[index].phone);
        printf("Informações do usuário atualizadas com sucesso!\n");
    } else {
        printf("Número de usuário inválido!\n");
    }
}


void deleteUser(User users[], int *numUsers) {
    int index;
    printf("Digite o número do usuário que deseja excluir: ");
    scanf("%d", &index);
    index--; // Ajuste para o índice do array
    if (index >= 0 && index < *numUsers) {
        for (int i = index; i < (*numUsers) - 1; i++) {
            strcpy(users[i].name, users[i+1].name);
            strcpy(users[i].email, users[i+1].email);
            users[i].age = users[i+1].age;
            strcpy(users[i].phone, users[i+1].phone);
        }
        (*numUsers)--;
        printf("Usuário excluído com sucesso!\n");
    } else {
        printf("Número de usuário inválido!\n");
    }
}

void generatePassword(char password[], int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>?";

    for (int i = 0; i < length; i++) {
        int index = rand() % (strlen(charset));
        password[i] = charset[index];
    }

    password[length] = '\0';
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;
    char newPassword[MAX_PASSWORD_LENGTH];

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar usuário\n");
        printf("2. Visualizar usuários\n");
        printf("3. Editar usuário\n");
        printf("4. Excluir usuário\n");
        printf("5. Gerar nova senha\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &numUsers);
                break;
            case 2:
                viewUsers(users, numUsers);
                break;
            case 3:
                editUser(users, numUsers);
                break;
            case 4:
                deleteUser(users, &numUsers);
                break;
            case 5:
                generatePassword(newPassword, MAX_PASSWORD_LENGTH - 1);
                printf("Nova senha gerada: %s\n", newPassword);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 0);

    return 0;
}