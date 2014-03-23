#include <stdio.h>

typedef unsigned long long ull;

int seen[10001];
ull lol[10001];

ull seq(int a) {
  if (a < 2) {
    return 1;
  }
  if (a == 2) {
    return 2;
  }
  if (a == 3) {
    return 4;
  }
  if (seen[a]) {
    return lol[a];
  }
  ull vvv = seq(a - 1) + seq(a - 2) + seq(a - 3) + seq (a - 4);
  lol[a] = vvv;
  seen[a] = 1;
  return vvv;
}

int main() {
  int n;
  scanf ("%d ", &n);
  int i;
  for (i = 0; i < n; i++) {
    int a;
    scanf("%d ", &a);
    printf("%llu\n", seq(a));
  }
  return 0;
}
