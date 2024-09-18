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
#include <stdarg.h>

#define MAX_STR_SIZE 256

char* readStringFromFile(FILE *fp, long pos) {
    fseek(fp, pos, SEEK_SET); // Go to the position where the string is stored
    int strLen;
    fread(&strLen, sizeof(int), 1, fp); // Read the length of the string
    char *str = malloc(strLen + 1); // Allocate memory for the string
    fread(str, sizeof(char), strLen, fp); // Read the string
    str[strLen] = '\0'; // Null-terminate the string
    return str;
}






void readContacts(char *fileName) {
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }


    struct Contact contact;
    while (fread(&contact, sizeof(contact), 1, fp) == 1) {
        printf("****************************\n");
        printf("Employee ID: %ld\n", contact.empId);
        printf("First Name: %s\n", contact.firstName);
        printf("Last Name: %s\n", contact.lastName);
        printf("Email: %s\n", contact.email);
        printf("****************************\n");
    }

    fclose(fp);
}

