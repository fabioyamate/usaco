/*
ID: fabioya1
LANG: C
PROG: friday
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leapyear(int year) {
  if (year % 100 == 0) {
    return year % 400 == 0;
  } else {
    return year % 4 == 0;
  }
}

int main(void) {
  FILE *fin  = fopen("friday.in", "r");
  FILE *fout = fopen("friday.out", "w");

  int n, year, i, w;

  /*                 J   F   M   A   M   J   J   A   S   O   N   D */
  int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int weekdays[7] = { 0 };

  fscanf(fin, "%d", &n);

  w = 2; /* monday */

  for (year = 1900; year < 1900 + n; ++year) {
    for (i = 0; i < 12; ++i) {
      weekdays[(w + 13 - 1) % 7] += 1;

      if (i == 1 && leapyear(year) == 1) {
        w = (w + 29) % 7;
      } else {
        w = (w + months[i]) % 7;
      }
    }
  }

  for (i = 0; i < 7; ++i) {
    if (i == 6) {
      fprintf(fout, "%d\n", weekdays[i]);
    } else {
      fprintf(fout, "%d ", weekdays[i]);
    }
  }

  exit(0);
}
