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

int categorized(struct RiderCategory* category,struct RiderInfo *info)
{

int i=0, size=14, b=0, c=0;
char ans[2];
printf("Which category (S, M, L): ");
scanf("%c", ans);
printf("\n");

for(i =0; i<size; i++){
  if (info[i].raceLength == ans[0]){
      for(c=0;c<30;c++){
      category[b].name[c] = info[i].name[c];
      }
      if (16 <= info[i].age && info[i].age <=20){
      strcpy(category[b].ageGroup, "Junior");
    }
     else if (21 <= info[i].age && info[i].age <=34){
      strcpy(category[b].ageGroup, "Adult");
    }
    if (info[i].age && info[i].age >= 34){
      strcpy(category[b].ageGroup, "Senior");
    }
      category[b].raceLength = info[i].raceLength;
      category[b].startTime = info[i].startTime;
      category[b].mountainTime = info[i].mountainTime;
      category[b].finishTime = info[i].finishTime;
      category[b].withdrawn = info[i].withdrawn;

      b++;
  }
  
}
return b;
}



int linecount(FILE *fp)
{
    int count = 0;

    char c; 

    // Extract characters from file and store in character c 

    for (c = getc(fp); c != EOF; c = getc(fp))

        if (c == '\n') // Increment count if this character is newline 

            count = count + 1;
    // Close the file 

    fclose(fp);

    return count + 1;

}


void filePrint(struct RiderCategory* p, int size){

int i=0;

printf("size: %d\n", size);
printf("Rider                    Age Group Time\n");
printf("---------------------------------------\n");
for(i=0; i<size; i++){
  
  printf("%-28s%-7s%5.2lf\n", p->name, p->ageGroup, p->finishTime);
  }

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

int getInt(void) {

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

    while (getchar() != '\n'); 

}





