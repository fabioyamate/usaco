/*
ID: fabioya1
LANG: C
PROG: ride
*/
#include <stdio.h>
#include <stdlib.h>

int number(const char *w) {
  int i, n = 1;
  for (i = 0; w[i] != '\0'; ++i) {
    n *= w[i] - 64;
  }
  return n % 47;
}

int hash(const char *w) {
  int n = 1;
  for (; *w != '\0'; w++) {
    n *= *w - 64;
  }
  return n % 47;
}

int hash2(const char *w) {
  int n;
  for (n = 1; *w != '\0'; n *= (*w++ - 64));
  return n % 47;
}

int hash3(const char *w) {
  int n;
  for (n = 1; *w; n *= (*w++ - 64));
  return n % 47;
}

int main(void) {
    FILE *fin  = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char a[7], b[7];
    fscanf(fin, "%s", a);
    fscanf(fin, "%s", b);

    if (hash2(a) == hash2(b))
      fprintf(fout, "GO\n");
    else
      fprintf(fout, "STAY\n");

    exit(0);
}
