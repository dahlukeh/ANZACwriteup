#include <cstdio>

#define dpp dp[i][x][y][z]
const int MAX = 1005;
const int UNKNOWN = -1000000;

int n;

int grid[3][MAX];
int dp[MAX][3][3][3];

int max(int a, int b) { return a > b ? a : b; }

int f(int i, int x, int y, int z) {
  if (i < 0) {
    return -1e9;
  }
  if (dpp == UNKNOWN) {
    if (x >= 1) {
      dpp = max(dpp, f(i, x - 1, y, z));
    }
    if (y >= 1) {
      dpp = max(dpp, f(i, x, y - 1, z));
    }
    if (z >= 1) {
      dpp = max(dpp, f(i, x, y, z - 1));
    }
    if (x == y && x > 0) {
      dpp = max(dpp, f(i, x - 1, y - 1, z) + grid[0][i + x - 1] * grid[1][i + y - 1]);
    }
    if (z == y && z > 0) {
      dpp = max(dpp, f(i, x, y - 1, z - 1) + grid[2][i + z - 1] * grid[1][i + y - 1]);
    }
    if (x >= 2) {
      dpp = max(dpp, f(i, x - 2, y, z) + grid[0][i + x - 1] * grid[0][i + x - 2]);
    }
    if (y >= 2) {
      dpp = max(dpp, f(i, x, y - 2, z) + grid[1][i + y - 1] * grid[1][i + y - 2]);
    }
    if (z >= 2) {
      dpp = max(dpp, f(i, x, y, z - 2) + grid[2][i + z - 1] * grid[2][i + z - 2]);
    }
    if (x < 2 && y < 2 && z < 2) {
      dpp = max(dpp, f(i - 1, x + 1, y + 1, z + 1));
    }
  }
//  printf("%d %d %d %d %d\n", i, x, y, z, dp[i][x][y][z]);

  return dp[i][x][y][z];
}

int main() {
  int tt = 1;
  while (scanf("%d ", &n), n) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d ", &grid[i][j]);
      }
    }

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            dp[i][j][k][l] = UNKNOWN;
          }
        }
      }
    }
    dp[0][0][0][0] = 0;
    printf("Case %d:", tt);
    tt++;
    printf(" %d\n", f(n, 0, 0, 0));
  }
  return 0;
}
