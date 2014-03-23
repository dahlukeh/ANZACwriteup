#include <stdio.h>

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  while (!feof(stdin)) {
    int a, b, c;
    scanf ("%d %d %d ", &a, &b, &c);
    int t = b * a;
    int bot = c - b;
    int ggg = gcd(bot, t);
    printf("%d/%d\n", t / ggg, bot / ggg);
  }
  return 0;  
}
