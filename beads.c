/*
ID: fabioya1
LANG: C
PROG: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fin  = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");

    int n, attempt, best, i, j, changed;
    char color;
    char necklace[800];

    fscanf(fin, "%d", &n);
    fscanf(fin, "%s", necklace);

    // duplicate the necklance
    strncpy(&necklace[n], necklace, n);

    best = 0;

    for (i = 0; i < n; ++i) {
      attempt = 0;
      color = 0;
      changed = 0;

      for (j = 0; j < n; ++j) {
        if (necklace[i+j] == 'w') { /* wildcard */
          attempt += 1;
        }
        else if (necklace[i+j] == 'r' || necklace[i+j] == 'b') {
          if (color == 0) { // set the initial bead color
            color = necklace[i+j];
          }

          if (color == necklace[i+j]) {
            attempt += 1;
          } else {
            if (changed) {
              break;
            } else {
              changed = 1;
              color = necklace[i+j];
              attempt += 1;
            }
          }
        }
      }

      if (attempt > best) {
        best = attempt;
      }
    }

    fprintf(fout, "%d\n", best);

    exit(0);
}
