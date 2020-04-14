/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Adam Bobbie              abobbie@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                FILE: file_helper.h                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

   /********************************************************/
   /* Define the missing members for the RiderInfo data    */
   /* used to store Rider information read from a file     */
   /********************************************************/
struct RiderInfo
{
    char name[20];
    int age;
    char raceLength;
    int startTime;
    int mountainTime;
    int finishTime;
    char withdrawn;
};

struct RiderCategory
{
    char name[20];
    char ageGroup[10];
    char raceLength;
    double startTime;
    double mountainTime;
    double finishTime;
    char withdrawn[5];
    
};


struct LastThreeRiders
{
    char name[20];
    char ageGroup[10];
    double time;
};

struct topThreeRiders
{
    char name[20];
    char ageGroup[10];
    double finalTime;
};



int menu(void);
int getIntInRange(int, int);
int getInt();
void clearKeyboard(void);
int linecount();
void fileprint();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/********************************************************/
/* Read all the information on one rider from the       */
/* file and store it in the struct. Return true         */
/* when end of file has been reached.                   */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info);

#endif
