/*
ID: fabioya1
LANG: C
PROG: milk2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slot {
  int start;
  int end;
  struct slot *next;
} Slot;

Slot* new_slot(int start, int end);

Slot* insert_slot(Slot* root, Slot* s);

Slot* merge_slot(Slot* s1, Slot* s2);

Slot* compact(Slot* root);

int main(void) {
    FILE *fin  = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");

    int n, i;
    int start, end;
    Slot *curr, *prev;
    Slot *root;

    int longest_milked = 0;
    int longest_not_milked = 0;

    root = NULL;

    fscanf(fin, "%d", &n);

    for (i = 0; i < n; ++i) {
      fscanf(fin, "%d %d", &start, &end);
      /* printf("%d %d->", start, end); */

      curr = new_slot(start, end);
      root = insert_slot(root, curr);
    }

    prev = NULL;
    curr = prev = root;
    while (curr != NULL) {
      /* printf("%d %d\n", curr->start, curr->end); */
      if (curr->end - curr->start > longest_milked) {
        longest_milked = curr->end - curr->start;
      }

      if (prev != NULL) {
        if (curr->start - prev->end > longest_not_milked) {
          longest_not_milked = curr->start - prev->end;
        }
      }

      prev = curr;
      curr = curr->next;
    }

    fprintf(fout, "%d %d\n", longest_milked, longest_not_milked);

    exit(0);
}

Slot* new_slot(int start, int end) {
  Slot* s = (Slot *) malloc(sizeof(Slot));
  s->start = start;
  s->end = end;
  s->next = NULL;
  return s;
}

Slot* insert_slot(Slot* root, Slot* s) {
  /* printf("inserting: (%d, %d)\n", s->start, s->end); */
  if (root == NULL) {
    return s;
  } else {
    if (root->end < s->start) {
      root->next = insert_slot(root->next, s);
      return root;
    } else if (root->start > s->end) {
      s->next = root;
      return s;
    } else {
      if (root->start > s->start) {
        root->start = s->start;
      }

      if (root->end < s->end) {
        root->end = s->end;
      }

      return compact(root);
    }
  }
}

Slot* compact(Slot* root) {
  /* printf("compacting...\n"); */
  if (root == NULL || root->next == NULL) {
    return root;
  } else {
    if (root->end > root->next->start) {
      return compact(merge_slot(root, root->next));
    } else {
      return root;
    }
  }
}

Slot* merge_slot(Slot* s1, Slot* s2) {
  if (s1 == NULL) {
    return s2;
  } else if (s2 == NULL) {
    return s1;
  } else { // merging
    /* printf("merging: (%d, %d) + (%d, %d)\n", s1->start, s1->end, s2->start, s2->end); */
    if (s1->start > s2->start) {
      s1->start = s2->start;
    }

    if (s1->end < s2->end) {
      s1->end = s2->end;
    }

    s1->next = s2->next;
    free(s2);

    return s1;
  }
}
