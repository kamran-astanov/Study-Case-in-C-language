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
        int size = linecount(fp);
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

int i=0, b=0, c=0;
int size = linecount(fp);
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


void lastThree(struct RiderCategory *p, struct LastThreeRiders *a, int size) 
{ 
    // Find first largest element
    int c=0, i=0; 
    a[0].time = 0; 
    for ( i = 0; i < size ; i++) {
        if (p[i].diffTime > a[0].time) {
            a[0].time = p[i].diffTime;
            for(c=0;c<15;c++){
            a[0].name[c] = p[i].name[c];}
	    for(c=0;c<9;c++){
            a[0].ageGroup[c] = p[i].ageGroup[c];
        }
    }
    }
    // Find second largest element 
    a[1].time = 0; 
    for (i = 0; i < size ; i++) {
        if (p[i].diffTime > a[1].time  && p[i].diffTime < a[0].time) {
            a[1].time = p[i].diffTime; 
            for(c=0;c<15;c++){
            a[1].name[c] = p[i].name[c]; }
	    for(c=0;c<9;c++){
            a[1].ageGroup[c] = p[i].ageGroup[c];
        }
        }
    }
    // Find third largest element 
    a[2].time = 0; 
    for ( i = 0; i < size ; i++) {
        if (p[i].diffTime > a[2].time && p[i].diffTime < a[1].time) {
            a[2].time = p[i].diffTime;
            for(c=0;c<15;c++){
            a[2].name[c] = p[i].name[c];}
	    for(c=0;c<9;c++){
            a[2].ageGroup[c] = p[i].ageGroup[c];
        }
        }
    }

int newsize=3;
printf("Rider                    Age Group Time\n");
printf("---------------------------------------\n");
for(i=0; i<newsize; i++){
  double firstnum = a[i].time;
  int hour = (int)firstnum;
  double minute = firstnum - hour;
  double finalnum = minute * 60;
  if(finalnum<10){
  printf("%-28s%-7s%d:0%.0lf\n", a[i].name, a[i].ageGroup, hour, finalnum);
  }
  else{
  printf("%-28s%-7s%d:%.0lf\n", a[i].name, a[i].ageGroup, hour, finalnum);
  }
}
} 


void topThree(struct RiderCategory *p, struct topThreeRiders *a, int size) {
  
  int c=0, i=0; 
   a[0].finalTime = 1000, a[1].finalTime = 1000, a[2].finalTime = 1000;
   for (int i = 0; i < size; i++) {
      if (p[i].diffTime < a[0].finalTime) {
         a[0].finalTime = p[i].diffTime;
          for(c=0;c<15;c++){
            a[0].name[c] = p[i].name[c]; }
            for(c=0;c<9;c++){
            a[0].ageGroup[c] = p[i].ageGroup[c];
        }
      }
   }
   for (int i = 0; i < size; i++){
     if (p[i].diffTime < a[1].finalTime && p[i].diffTime > a[0].finalTime) {
         a[1].finalTime = p[i].diffTime;
         for(c=0;c<15;c++){
            a[1].name[c] = p[i].name[c]; }
            for(c=0;c<9;c++){
            a[1].ageGroup[c] = p[i].ageGroup[c];
        }
     }
   }
   for (int i = 0; i < size; i++){
     if (p[i].diffTime < a[2].finalTime && p[i].diffTime > a[1].finalTime){
        a[2].finalTime = p[i].diffTime;
     
        for(c=0;c<15;c++){
            a[2].name[c] = p[i].name[c];}
            for(c=0;c<9;c++){
            a[2].ageGroup[c] = p[i].ageGroup[c];
        }
   }
   }
  
int newsize=3;
printf("Rider                    Age Group Time\n");
printf("---------------------------------------\n");
for(i=0; i<newsize; i++){
  double firstnum = a[i].finalTime;
  int hour = (int)firstnum;
  double minute = firstnum - hour;
  double finalnum = minute * 60;
  if(finalnum<10){
  printf("%-28s%-7s%d:0%.0lf\n", a[i].name, a[i].ageGroup, hour, finalnum);
  }
  else{
  printf("%-28s%-7s%d:%.0lf\n", a[i].name, a[i].ageGroup, hour, finalnum);
  }
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





