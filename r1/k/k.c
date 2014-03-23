#include <stdio.h>


int main() {
  int n;
  scanf ("%d ", &n);
  int i, j;
  for (i = 0; i < n; i++) {
    int lol = 1 << 20;
    int total = 0;
    for (j = 0; j < 20; j++) {
      int a;
      scanf ("%d ", &a);
      total += a * lol;
      lol /= 2;
    }
    lol = 1 << 20;
    printf("%d", total / lol);
    for (j = 0; j < 19; j++) {
      lol /= 2;
      if (total & lol) {
        printf(" 1");
      } else {
        printf (" 0");
      }
    }
    printf("\n");
  }
}
