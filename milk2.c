/*
ID: fabioya1
LANG: C
PROG: milk2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fin  = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");

    int n;
    int i;
    int current_start, current_end;
    int start, end;

    int milked = 0, not_milked = 0;
    int longest_milked = 0, longest_not_milked = 0;

    fscanf(fin, "%d", &n);

    current_start = 0;
    current_end = 0;

    milked = 0;
    not_milked = 0;

    for (i = 0; i < n; ++i) {
      fscanf(fin, "%d %d", &start, &end);

      if (!i) current_end = start;

      if (start > current_end) {
        not_milked = start - current_end;
        milked = end - start;
        current_start = start;
        current_end = end;
      } else {
        milked += end - current_end;
        current_end = end;
      }

      if (milked > longest_milked) {
        longest_milked = milked;
      }

      if (not_milked > longest_not_milked) {
        longest_not_milked = not_milked;
      }
    }

    fprintf(fout, "%d %d\n", longest_milked, longest_not_milked);

    exit(0);
}
