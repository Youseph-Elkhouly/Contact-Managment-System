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
#include "givenA2.h" // Make sure this is the correct path to your struct definition

int searchContacts(char *fileName, int empId) {
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 0; // Return 0 if file cannot be opened
    }

    struct Contact contact;
    int contactFound = 0; // Flag to indicate if contact is found

    while (fread(&contact, sizeof(contact), 1, fp) == 1) {
        if (contact.empId == empId) {
            // Contact found, display information
            printf("****************************\n");
            printf("Employee ID: %ld\n", contact.empId);
            printf("First Name: %s\n", contact.firstName);
            printf("Last Name: %s\n", contact.lastName);
            printf("Email: %s\n", contact.email);
            printf("****************************\n");
            contactFound = 1; // Set flag to indicate contact is found
            break;
        }
    }

    fclose(fp);

    if (!contactFound) {
        printf("No contact found with Employee ID: %d\n", empId);
        return 0; // No contact found
    }
    return 1; // Contact found
}

