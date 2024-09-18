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
#include <ctype.h>


// Definition of flushInputBuffer function
void flushInputBuffer(void);


void writeContactToFile(FILE *fp, struct Contact *contact, const char *firstName, const char *lastName, const char *email) {
    fseek(fp, 0, SEEK_END); // Move to the end of the file
    long position = ftell(fp); // Get the current position

    // Write the contact structure to the file
    fwrite(contact, sizeof(struct Contact), 1, fp);

    // Write the positions of the strings to the file
    fprintf(fp, "%ld %ld %ld\n", position, position + sizeof(int), position + sizeof(int) + sizeof(int));
}








char* getString() {
    char buffer[1024]; // Define a large enough buffer for input
    printf("Enter the value: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL; // Error or end of file
    }

    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = 0;

    // Dynamically allocate memory for the exact length of the input
    char* line = malloc(strlen(buffer) + 1);
    if (line != NULL) {
        strcpy(line, buffer);
    }

    return line;
}

long writeStringToFile(FILE *fp, const char *str) {
    int length = strlen(str);
    fwrite(&length, sizeof(int), 1, fp);
    fwrite(str, sizeof(char), length, fp);
    return ftell(fp) - length - sizeof(int);
}




