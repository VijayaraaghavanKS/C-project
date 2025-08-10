#include <stdio.h>
#include <string.h>
// Define a structure to store user credentials
typedef struct UserCredentials {
    char email[50];
    char password[50];
}Cred;
int main() {
    // Initialize an array of 5 user credentials
    Cred users[5] = {
        {"user1@example.com", "passwd1234"},
        {"user2@example.com", "securePass56"},
        {"user3@example.com", "myPassword789"},
        {"user4@example.com", "iamwhoiam12"},
        {"user5@example.com", "passispass1@"}
    };
    // Display the user credentials
    printf("Stored User Credentials:\n");
    for (int i = 0; i < 5; i++) {
        printf("User %d:\n", i + 1);
        printf("  Email: %s\n", users[i].email);
        printf("  Password: %s\n\n", users[i].password);
    }
    return 0;
}