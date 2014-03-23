#include <cstdio>

const int MAX = 10;

char toMatch[MAX];
char in[1000][MAX];

bool matches[1000];

int main() {
  scanf("%s ", toMatch);
  int n;
  scanf("%d ", &n);
  int found = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s ", in[i]);
    matches[i] = true;
    for (int j = 0; j < 9; j++) {
      if (toMatch[j] != '*' && toMatch[j] != in[i][j]) {
        matches[i] = false;
      }
    }
    if (matches[i]) {
      found++;
    }
  }
  printf("%d\n", found);
  for (int i = 0; i < n; i++) {
    if (matches[i]) {
      printf("%s\n", in[i]);
    }
  }
  return 0;
}

