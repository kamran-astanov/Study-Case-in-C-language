/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)
   2)
   3)

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"
#include <stdio.h>
int main(void) {

  FILE *fp;
  fp = fopen("data.txt", "r");
  struct RiderInfo riders[14];
  struct RiderCategory category[14];
  struct LastThreeRiders last[14];
  struct topThreeRiders top[14];
  struct winnerRiders winners[14];
  readFileRecord(fp, riders); 
  int size = categorized(category, riders);
  lastThree(category, last, size);
  topThree(category, top, size);
  allRiders(category,size);
  winnerRiders(riders, winners);

  
}
/*{
    int lines;
    lines = linecount("data.txt");
    printf("data.txt contains %d lines.", lines);
    printf("\n\n\n\n\n\n");
    fileprint();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}*/
    // TODO: Code the necessary logic for your solution below
    //
    // NOTE: Use modularity whenever possible in your design
    //
    // HINTS:
    // 1) You will need to load the file data and store
    //    it to a data structure array 
    //    (MUST USE: provided "readFileRecord" function)
    //
    // 2) Create a menu system to provide the user with
    //    the reporting options
    //
    // 3) Generate the user-selected report
