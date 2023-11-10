#include <stdio.h>
#include <string.h>
#define MAX_USERS 10

struct User {
    char username[50];
    char password[50];
    int Active;
};

struct User users[MAX_USERS];
int userCount = 0;
void Register() {
    if (userCount < MAX_USERS) {
        struct User newUser;

        printf("Enter a username: ");
        scanf("%s", newUser.username);
        printf("Enter a password: ");
        scanf("%s", newUser.password);
        printf("Enter a Active of Account 0 Or 1 : ");
        scanf("%d", &newUser.Active);
        users[userCount] = newUser;
        userCount++;
        printf("\n==========================\n");
        printf("Registration successful!\n");
        printf("==========================\n");
    } else {
        printf("\n==========================\n");
        printf(" Cannot register more users.\n");
        printf("==========================\n");
    }
}
int Login(char *username,char *password){
    for(int i=0;i<userCount;i++){
     if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 && users[i].Active==1) {
            return 1; // User found
        }}
    return 0;
}

int main() {
    int choice;
    char username[50];
    char password[50];

    while (1) {
        printf("\n1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Register();
                break;
            case 2:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                if (Login(username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Please check your username and password. || or || Account is not active !\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
