#include <cstdio>

const int MAX = 10;

char toMatch[MAX];
char in[1000][MAX];

bool fuck[1000];

int main() {
  scanf("%s ", toMatch);
  int n;
  scanf("%d ", &n);
  int found = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s ", in[i]);
    fuck[i] = true;
    for (int j = 0; j < 9; j++) {
      if (toMatch[j] != '*' && toMatch[j] != in[i][j]) {
        fuck[i] = false;
      }
    }
    if (fuck[i]) {
      found++;
    }
  }
  printf("%d\n", found);
  for (int i = 0; i < n; i++) {
    if (fuck[i]) {
      printf("%s\n", in[i]);
    }
  }
  return 0;
}

