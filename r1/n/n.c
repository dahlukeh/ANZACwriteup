#include <stdio.h>

#define TRUE    1
#define FALSE   0

int valid[130][130][4];
int seen[130][130];

int tY, tX;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void reset() {
  int i, j, k;
  for (i = 0; i < 130; i++) {
    for (j = 0; j < 130; j++) {
      for (k = 0; k < 4; k++) {
        valid[i][j][k] = FALSE;
      }
      seen[i][j] = -1;
    }
  }
}

int find(int y, int x) {
  if (seen[y][x] != -1) {
    return seen[y][x];
  }
  if (y == tY && x == tX) {
    return 0;
  }
  seen[y][x] = 1000000;
  int i;
  int best = 100000;
  for (i = 0; i < 4; i++) {
    int newX = dx[i] + x;
    int newY = dy[i] + y;
    if (valid[y][x][i]) {
      int res = find(newY, newX) + 1;
      if (res < best) {
        best = res;
      }
    }
  }
  seen[y][x] = best;
  return best;
}


int main() {
  int n;
  scanf ("%d ", &n);
  int i, j;
  for (i = 0; i < n; i++) {
    reset();
    int s;
    scanf ("%d ", &s);
    int x = 63;
    int y = 63;
    for (j = 0; j < s; j++) {
      char c;
      int d;
      scanf (" %c ", &c);
      if (c == 'S') {
        d = 0;
      } else if (c == 'N') {
        d = 2;
      } else if (c == 'E') {
        d = 1;
      } else {
        d = 3;
      }
      valid[y][x][d] = TRUE;
      y += dy[d];
      x += dx[d];
      valid[y][x][(d + 2) % 4] = TRUE;
    }
    tY = y;
    tX = x;
    printf("%d\n", find(63, 63));
  }
  return 0;
}
