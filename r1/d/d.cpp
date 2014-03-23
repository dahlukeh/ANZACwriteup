#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 200;

int n, e;

struct point {
  int f, x, y;
};

point points[MAX];

double bestDist[MAX][MAX];
int via[MAX][MAX];
/*
void gogo(int a, int b) {
  if (a == b) {
    printf("%d ", a);
  } else if (via[a][b] == a || via[a][b] == b || via[a][b] == -1) {
    printf("%d %d ", a, b);
  } else {
    gogo(a, via[a][b]);
    gogo(via[a][b], b);
  }
}
*/

void gogo(int a, int b) {
  if (via[a][b] == -1) {
    printf("%d ", a);
  } else {
    gogo(a, via[a][b]);
    gogo(via[a][b], b);
  }
}

int main() {
  scanf("%d %d ", &n, &e);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bestDist[i][j] = 1e8;
      via[i][j] = -1;
    }
    bestDist[i][i] = 0;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &points[i].f, &points[i].x, &points[i].y);
  }
  for (int i = 0; i < e; i++) {
    int from, to;
    char type[50];
    scanf("%d %d %s ", &from, &to, type);
    double dx = points[to].x - points[from].x;
    double dy = points[to].y - points[from].y;
    double df = (points[to].f - points[from].f) * 5;
    double dd =  sqrt(dx * dx + dy * dy + df * df);
    if (!strcmp(type, "walking") || !strcmp(type, "stairs")) {
      bestDist[to][from] = min(bestDist[to][from], dd);
      bestDist[from][to] = min(bestDist[from][to], dd);
    } else if (!strcmp(type, "lift")) {
      // TODO min this
      bestDist[to][from] = min(bestDist[to][from], 1.0);
      bestDist[from][to] = min(bestDist[from][to], 1.0);
    } else if (!strcmp(type, "escalator")) {
      bestDist[from][to] = min(bestDist[from][to], 1.0);
      bestDist[to][from] = min(bestDist[to][from], 3 * dd);
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        double possible = bestDist[i][k] + bestDist[k][j];
        if (possible < bestDist[i][j]) {
          bestDist[i][j] = possible;
          via[i][j] = k;
        }
      }
    }
  }

  int t;
  scanf("%d ", &t);
  for (int i = 0; i < t; i++) {
    int from, to;
    scanf("%d %d ", &from, &to);
    gogo(from, to);
    printf("%d\n", to);
  }
  return 0;
}
