#include <stdio.h>

#define TRUE    1
#define FALSE   0

#define INF     (1 << 29)

int n;

int canGo[1001][1001];

int best[1001];
int marked[1001];
int tar;

int min (int a, int b) { return a < b ? a : b;}

int findBest(int at) {
  int i;
  for (i = 0; i <= 1000; i++) {
    best[i] = INF;
    marked[i] = FALSE;
  }
  best[at] = 0;
  while (TRUE) {
    // FInd best unmarked
    int b = INF;
    int bb = 0;
    for (i = 0; i <= 1000; i++) {
      if (!marked[i] && best[i] < b) {
        b = best[i];
        bb = i;
      }
    }
    if (bb == tar) {
      return best[bb];
    }
    marked[bb] = TRUE;
    for (i = 0; i <= 1000; i++) {
      int newDis = best[bb] + canGo[bb][i];
      if (newDis < best[i]) {
        best[i] = newDis;
      }
    }
  }
  return -1;
}

void reset() {
  int i, j;
  for (i = 0; i <= 1000; i++) {
    best[i] = -1;
    for (j = 0; j <= 1000; j++) {
      canGo[i][j] = INF;
    }
  }
}

void handle() {
  int i;
  reset();
  for (i = 0; i < n; i++) {
    int a, b, c;
    scanf ("%d %d %d ", &a, &b, &c);
    int cost = (a + b) * c;
    canGo[a][b] = min(canGo[a][b], cost);
    canGo[b][a] = min(canGo[b][a], cost);
  }
  int s;
  scanf ("%d %d ", &s, &tar);
  int rrr = findBest(s);
  printf("%d.%02d\n", rrr / 100, rrr % 100);
}

int main() {
  scanf ("%d ", &n);
  while (n != 0) {
    handle();
    scanf("%d ", &n);
  }
  return 0;
}
