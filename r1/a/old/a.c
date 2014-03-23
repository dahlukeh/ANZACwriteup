#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char recording[10002];
char made[101][102];
int nmade;

void get(int *i, char *rec, char *word) {
  char *s = word;
  while (rec[*i] != ' ') {
    word[*i] = rec[*i];
    ++*i;
  }
}

int main(void) {
  int T, t, i;
  scanf("%d\n", &T);
  for (t = 0; t < T; ++t) {
    char s[102];
    int i, j, n;
    nmade = 0;
    fgets(recording, 10002, stdin);
    for (;;) {
      fgets(made[i], 102, stdin);
      if (!strcmp(made[i], "what does the fox say?\n")) break;
      made[i][strlen(made[i]) - 1] = 0;
      printf("m %s\n", made[i]);
    }
    /*
    n = strlen(recording);
    i = 0; j = 0;
    while (recording[i] != '\n') {
      get(&i, recording, s);
      printf("word %s\n", s);
      ++i;
    */
    printf("rec %s\n", recording);
  }
  exit(EXIT_SUCCESS);
}
