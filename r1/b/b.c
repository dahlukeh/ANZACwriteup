#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

int n, k;
int isSpecial[5001];
char influences[5001][5001];

int doneStuff[5001];
void findAll(int a) {
  if (doneStuff[a]) {
    return;
  }
  int i, j;
  for (i = 1; i<= n;i++) {
    if(influences[a][i]) {
      findAll(i);
      for (j = 1; j <= n; j++) {
        influences[a][j] |= influences[i][j];
      }
    }
  }
  doneStuff[a] = TRUE;
}

int main() {
  scanf("%d %d ", &n, &k);
  int i, j;
  for (i = 0; i < k; i++) {
    int a;
    scanf("%d ", &a);
    isSpecial[a] = TRUE;
  }
  for (i = 0; i < n; i++) {
    int a;
    scanf(" %d", &a);
    char c;
    c = getchar();
    int cur = 0;
    while (c != '\n') {
      if (c == ' ') {
        if (cur > 0) {
          influences[a][cur] = TRUE;
        }
        cur = 0;
      } else {
        cur *= 10;
        cur += c - '0';
      }
      c = getchar();
    }
    if (cur > 0) {
      influences[a][cur] = TRUE;
    }
  }
  int best = -1;
  int curBest = 1;
  for (i = 1; i <= n; i++) {
    findAll(i);
    if (isSpecial[i]) {
      int count = 0;
      for (j = 1; j <= n; j++) {
        if (influences[i][j]) {
          count++;
        }
      }
      if (count > best) {
        best = count;
        curBest = i;
      }
    }
  }
  printf("%d\n", curBest);
  return 0;
}
