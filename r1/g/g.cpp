#include <cstdio>

const int UNKNOWN = -1;
const int MAX = 1000;

int n1, n2, m;

int t1[MAX], t2[MAX];

void insert(int t, int x) {
  if (t == 0) {
    if (t1[x % n1] != UNKNOWN) {
      int next = t1[x % n1];
      t1[x % n1] = x;
      insert(1, next);
    } else {
      t1[x % n1] = x;
    }
  } else {
    if (t2[x % n2] != UNKNOWN) {
      int next = t2[x % n2];
      t2[x % n2] = x;
      insert(0, next);
    } else {
      t2[x % n2] = x;
    }
  }
}

int main() {
  int t = 1;
  while (scanf("%d %d %d ", &n1, &n2, &m), m) {
    for (int i = 0; i < MAX; i++) {
      t1[i] = t2[i] = UNKNOWN;
    }
    for (int i = 0; i < m; i++) {
      int in;
      scanf("%d ", &in);
      insert(0, in);
    }
    printf("Case %d:\n", t);
    t++;
    int nn1 = 0, nn2 = 0;
    for (int i = 0; i < n1; i++) {
      if (t1[i] != UNKNOWN) {
        nn1++;
      }
    }
    for (int i = 0; i < n2; i++) {
      if (t2[i] != UNKNOWN) {
        nn2++;
      }
    }
    if (nn1) {
      printf("Table 1\n");
    }
    for (int i = 0; i < n1; i++) {
      if (t1[i] != UNKNOWN) {
        printf("%d:%d\n", i, t1[i]);
      }
    }
    if (nn2) {
      printf("Table 2\n");
    }
    for (int i = 0; i < n2; i++) {
      if (t2[i] != UNKNOWN) {
        printf("%d:%d\n", i, t2[i]);
      }
    }
  }
  return 0;
}
