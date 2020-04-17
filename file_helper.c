/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)
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
int readFileRecord(const char *filename, struct RiderInfo* info, int sizeofline)

{
    FILE *fp = fopen(filename, "r"); 
    int result = 1, ch;
    if (!feof(fp))
{
        int i = 0;
        // read from file and assign to data structure
        for (i = 0; i < sizeofline; i++) {
            fscanf(fp, "%[^,]%*c", info[i].name);
            fscanf(fp, "%d", &info[i].age);
            fscanf(fp, " %c", &info[i].raceLength);
            info[i].startTime = readTime(fp);
            info[i].mountainTime = readTime(fp);
            info[i].finishTime = readTime(fp);
            //Last Field (withdrawn: may not be present)
            ch = fgetc(fp);
            info[i].withdrawn = 0;
            if (ch == ' ')
            {
                ch = fgetc(fp);
                info[i].withdrawn = ch;
                ch = fgetc(fp);
            }
            // clear input file buffer until end of line (record):
            while (!feof(fp) && ch != '\n')
            {
                ch = fgetc(fp);
            }
            result = 0;
    }
    } 
    return result;
}
