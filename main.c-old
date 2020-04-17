#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "file_helper.h"
#include "myfile.h"

#define MAX 5000


int main(void) {
  

  const char filename[] = "data.txt";

  struct RiderInfo riders[MAX];

  struct RiderCategory category[MAX];

  struct LastThreeRiders last[MAX];

  struct topThreeRiders top[MAX];

  struct winnerRiders winners[MAX];

  int sizeofline = linecount(filename);

  readFileRecord(filename, riders, sizeofline); 

  int size = categorized(category, riders, sizeofline);

  lastThree(category, last, size);

  topThree(category, top, size);

  allRiders(category,size);

  winnerRiders(riders, winners);
 
 
 //printf("size: %d\n", size );

// printf("sizeofline: %.2lf\n", category[0].diffTime);

}
