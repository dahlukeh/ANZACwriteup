#include <stdio.h>

#define TRUE    1
#define FALSE   0

typedef unsigned long long ull;

ull a, b, c;

// [0]^[1]
int lookup[150000][2];

ull best[150000][20];
int seen[150000][20];

int numFact;
ull primeFact[20];
ull powe[20];

void reset() {
  numFact = 0;
}

ull dp(int at, int h) {
  if (seen[at][h]) {
    return best[at][h];
  }
  if (at == 1) {
    return 1ll;
  }

  int i;
  ull res = 0ll;
  int nextNum = (lookup[at][1]);
  for (i = 1; i <= lookup[at][1]; i++) {
    if (nextNum % i == 0) {
      res += dp(nextNum / i, h + 1);
    }
  }
  best[at][h] = res;
  return res;
}

void handle() {
  reset();
  int i, j;
  int cur = (int) b;
  for (i = 2; i <= 10000 && cur > 1; i++) {
    if (cur % i == 0) {
      primeFact[numFact] = i;
      powe[numFact] = 0;
      while (cur % i == 0) {
        powe[numFact]++;
        cur /= i;
      }
      numFact++;
    }
  }
  for (i = 0; i < numFact; i++) {
    powe[i] *= c;
  }
  int powOfA = lookup[a][1];
  for (i = 2; i <= 20; i++) {
    if (powOfA % i == 0) {
      int count = 0;
      while (powOfA % i == 0) {
        powOfA /= i;
        count++;
      }
      int found = FALSE;
      for (j = 0; j < numFact && !found; j++) {
        if (primeFact[j] == i) {
          powe[j] += count;
          found = TRUE;
        }
      }
      if (!found) {
        primeFact[numFact] = i;
        powe[numFact] = count;
        numFact++;
      }
    }
  }
  ull ove = 0ll;
  for (i = 2; i <= 150000; i++) {
    ull total = 1ll;
    for (j = 0; j < numFact; j++) {
      total *= (powe[j] / (ull) i) + 1ll;
    }
    total--;
    if (total > 0) {
      ove += total * dp(i, 0);
    }
  }
  printf("%llu\n", ove);
}

int main() {
  int i, j;
  for (i = 2; i <= 150000; i++) {
    ull cur = (ull) i;
    for (j = 1; cur <= 150000ll; j++) {
      if (lookup[cur][0] == 0) {
        lookup[cur][0] = i;
        lookup[cur][1] = j;
      }
      cur *= (ull) i;
    }
  }
  while (!feof(stdin)) {
    scanf ("%llu%*c%llu%*c%llu ", &a, &b, &c);
    handle();
  }
  return 0;
}


