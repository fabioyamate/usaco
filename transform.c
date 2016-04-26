/*
ID: fabioya1
LANG: C
PROG: transform
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 10

void print_table(int n, char table[][N_MAX+1]);
void rotate90(int n, char table[][N_MAX+1]);

int main(void) {
    printf("foo");
    FILE *fin  = fopen("transform.in", "r");
    /* FILE *fout = fopen("transform.out", "w"); */

    int n, i;

    char table[N_MAX+1][N_MAX+1];
    printf("foo");

    fscanf(fin, "%d", &n);

    printf("foo");
    for (i = 0; i < n; ++i) {
      fscanf(fin, "%s", table[i]);
    }
    printf("foo");

    rotate90(n, table);
    print_table(n, table);

    printf("foo");
    return 0;
}

void print_table(int n, char table[][N_MAX+1]) {
//void print_table(int n, char table[][]) {
  int i;

  for (i = 0; i < n; ++i) {
    printf("%s\n", table[i]);
  }
}

void rotate90(int n, char table[][N_MAX+1]) {
// char[][] rotate90(int n, char table[][]) {
  int i, j;
  char t[N_MAX+1][N_MAX+1];

  for (i = 0; i < n; ++i) {
    for (j = 0; i < n; ++j) {
      t[i][j] = table[n-i][i];
    }
  }

  for (i = 0; i < n; ++i) {
    for (j = 0; i < n; ++j) {
      table[i][j] = t[i][j];
    }
  }
}

/* 0,0 0,1 0,2 */
/* 1,0 1,1 1,2 */
/* 2,0 2,1 2,2 */

/* 2,0 1,0 0,0 */
/* 2,1 1,1 0,1 */
/* 2,2 1,2 0,2 */
