/*
Student Name: Youseph El-Khouly
Student ID: 1281324
Due Date: 2024-03-10
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "givenA2.h"
#include <strings.h>

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void createContacts(char *fileName) {
    FILE *fp = fopen(fileName, "ab+"); // Open for appending; plus reading.
    if (!fp) {
        perror("Failed to open file for updating");
        return;
    }

    // Struct Contact is packed to prevent padding issues.
    struct Contact newContact;

    // Clear any existing content in the struct to prevent garbage/memory junk from being written.
    memset(&newContact, 0, sizeof(newContact));

    printf("Employee Id: ");
    scanf("%ld", &newContact.empId);
    flushInputBuffer();

    printf("First Name: ");
    fgets(newContact.firstName, MAX_NAME_LENGTH, stdin);
    newContact.firstName[strcspn(newContact.firstName, "\n")] = 0; // Remove newline.

    printf("Last Name: ");
    fgets(newContact.lastName, MAX_NAME_LENGTH, stdin);
    newContact.lastName[strcspn(newContact.lastName, "\n")] = 0; // Remove newline.

    printf("Email: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline.

    // Write the new contact to the file in binary mode to match the read mode.
    fwrite(&newContact, sizeof(struct Contact), 1, fp);

    fclose(fp);
    printf("Contact added successfully.\n");
}


void mainMenu(char *fileName);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];
    char response[10];


    printf("Do you wish to enter a new contact (Yes or No)?: ");
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] = 0;

    if (strcasecmp(response, "yes") == 0) {
        // If yes, proceed to create contacts.
        createContacts(fileName);
    }

    // After handling the initial contact creation or if the user chooses not to create a contact,
    // proceed to the main menu for further actions.
    mainMenu(fileName);

    return 0;
}

void mainMenu(char *fileName) {
    while (1) {
        int option;
        printf("\nEnter a choice:\n");
        printf("1 to print, 2 to search, 3 to add more contacts, -1 to exit: ");
        scanf("%d", &option); // Using scanf to directly capture the user's choice.
        flushInputBuffer(); // Clearing buffer after scanf to prevent input skipping.

        switch (option) {
            case 1:
                readContacts(fileName);
                break;
            case 2:
                printf("Search for Employee Id? ");
                int empId;
                scanf("%d", &empId);
                flushInputBuffer();
                searchContacts(fileName, empId);
                break;
            case 3:
                // Assuming createContacts will internally manage prompting the user for "Yes" or "No".
                createContacts(fileName);
                break;
            case -1:
                printf("Exiting.\n");
                return; // Exiting the loop and the program.
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

