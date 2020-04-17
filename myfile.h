/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Kamran Astanov            kastanov@myseneca.ca
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000



struct RiderCategory
{
    char name[20];
    char ageGroup[10];
    char raceLength;
    double startTime;
    double mountainTime;
    double finishTime;
    double diffTime;
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

struct winnerRiders
{
    char name[20];
    char ageGroup[10];
    char raceGroup[10];
    double finalTime;
};

struct RiderInfo riders[MAX];
struct RiderCategory category[MAX];
struct LastThreeRiders last[MAX];
struct topThreeRiders top[MAX];
struct winnerRiders winners[MAX];

int linecount(const char *filename);
int categorized(struct RiderCategory[],struct RiderInfo[] , int);
void lastThree(struct RiderCategory[], struct LastThreeRiders[], int);
void topThree(struct RiderCategory[], struct topThreeRiders[], int);
void allRiders (struct RiderCategory[], int);
void winnerRiders(struct RiderInfo[], struct winnerRiders[]);
int menu(void);
int getIntInRange(int , int );
int getInt(void);
void clearKeyboard(void);
int yes(void);
void riderCompetition(int sizeofline);
