#include <stdio.h>

char str1[15];
char str2[15];

int main() {
  int n;
  scanf ("%d ", &n);
  while (n != 0) {
    int i, j;
    int has[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < n; i++) {
      int a;
      scanf ("%d ", &a);
      has[a]++;
    }
    int len1 = n / 2;
    int len2 = n - len1;
    // place in 2 first
    int list[16];
    int upTo = 0;
    for (i = 1; i <= 9; i++) {
      for (j = 0; j < has[i]; j++) {
        list[upTo++] = i;
      }
    }
    for (i = 0; i < 15; i++) {
      str1[i] = 0;
      str2[i] = 0;
    }
    // place 0's
    for (i = 0; i < has[0]; i++) {
      if (i % 2 == 0) {
        // Place it into str2
        str2[1 + (i / 2)] = '0';
      } else {
        str1[1 + (i / 2)] = '0'; 
      }
    }
    int place1 = 0;
    int place2 = 0;
    for (i = 0; i < upTo; i++) {
      if (place2 <= place1) {
        str2[place2++] = list[i] + '0';
        while (str2[place2] != 0) {
          place2++;
        }
      } else {
        str1[place1++] = list[i] + '0';
        while (str1[place1] != 0) {
          place1++;
        }
      }
    }
    int aaaa, bbbb;
    sscanf(str1, "%d", &aaaa);
    sscanf(str2, "%d", &bbbb);
    printf ("%d\n", aaaa + bbbb);
    scanf ("%d ", &n);
  }
  return 0;
}

