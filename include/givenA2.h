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





#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
struct Contact {
    long empId;
    long firstNamePosn;
    long lastNamePosn;
    long emailPosn;
    long next;
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	char email[MAX_EMAIL_LENGTH]
};


#pragma pack(pop)

// Function prototypes
void createContacts(char *fileName);
void readContacts(char *fileName); // To read and display contacts from the file
int searchContacts(char* fileName, int empID); // To search for a contact by ID
char* readStringFromFile(FILE *fp, long pos); // Utility to read strings from file
long writeStringToFile(FILE *fp, const char *str); // Utility to write strings to file
void writeContactToFile(FILE *fp, struct Contact *contact, const char *firstName, const char *lastName, const char *email);



