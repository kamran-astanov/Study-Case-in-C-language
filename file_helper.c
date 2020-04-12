/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Adam Bobbie				abobbie@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   |  !!!      DO NOT ALTER THE CONTENTS BELOW         !!!  |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include "file_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
   /********************************************************/
   /* Read from the opened file the time (HH:MM) parts of  */
   /* the record and return the time as decimal hours      */
   /********************************************************/
double readTime(FILE* fp)
{
	int hour, min;

	fscanf(fp, "%d%*c", &hour);
	fscanf(fp, "%d", &min);

	return hour + (min / 60.0);
}

/********************************************************/
/* Read all the information on one rider from the valid */
/* (pre-opened) file and store it in the struct.        */
/* Return true when end of file has been reached.       */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info)
{
    int result = 1, ch;

    if (!feof(fp))
    {
        char ans[2];
        int i = 0;
        int size = linecount("data.txt");
        // read from file and assign to data structure
        for (i = 0; i < size; i++) {
            fscanf(fp, "%[^,]%*c", info[i].name);
            fscanf(fp, "%d", &info[i].age);
            fscanf(fp, " %c", &info[i].raceLength);
            info[i].startTime = readTime(fp);
            info[i].mountainTime = readTime(fp);
            info[i].finishTime = readTime(fp);



            //Last Field (withdrawn: may not be present)
            ch = fgetc(fp);
            info->withdrawn = 0;

            if (ch == ' ')
            {
                ch = fgetc(fp);
                info->withdrawn = ch == 'W';
                ch = fgetc(fp);
            }

            // clear input file buffer until end of line (record):
            while (!feof(fp) && ch != '\n')
            {
                ch = fgetc(fp);
            }
            result = 0;

        }
        result = 0;
    }



    return result;
}

int menu(void) {
    //int choice;
    printf("******************** Seneca Cycline Race Results ********************\n");
    printf("What would you like to do?\n");
    printf("0 - Exit\n");
    printf("1 = Print Top 3 Riders in a category\n");
    printf("2 - Print all riders in a category\n");
    printf("3 - Print last 3 riders in a category\n");
    printf("4 - Print winners in all categories\n");
    printf(": ");
    printf("0. Exit\n");
    return getIntInRange(0, 6);
    printf("\n");
}
int getIntInRange(int min, int max) {
    int value;
    value = getInt();
    while (value < min || value > max) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        value = getInt();
    }
    return value;
}
int getInt() {
    int value;
    char newline = 'x';
    scanf("%d%c", &value, &newline);
    while (newline != '\n') {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &newline);
    }
    return value;
}
void clearKeyboard(void) {
    while (getchar() != '\n'); // empty execution code block on purpose
}
int linecount(filename)
{
    FILE* fp;
    int count = 0;
    char c; 
    fp = fopen(filename, "r");


    // Extract characters from file and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline 
            count = count + 1;

    // Close the file 
    fclose(fp);
    return count + 1;
}
/*void fileprint() {
    int lcount = linecount("data.txt");
    FILE* fp = fopen("data.txt", "r");
    int i = 1;
    while(i < lcount) {
        fgets(i, 50, fp);
        printf("%s\n", i);
        i++;
        printf("%s", i);
    }
    printf("%d\n", i);
}*/
void fileprint()
{
    
    char new_num[SIZE];
    FILE* ifp = NULL;
    int i, j, n, m;

    
    ifp = fopen("data.txt", "r");
    if (ifp != NULL)
    {
        fscanf(ifp, "%d %d", &n, &m);
        printf("Data from the file: %d, %d \n", n, m);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(ifp, "%s", new_num);
            printf("new num : %s\n ", new_num);
        }
    }
    fclose(ifp);
    return 0;
}