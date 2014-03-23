#include <cstdio>
#include <vector>
using namespace std;

vector<int> left, right;

int main() {
  int tt;
  scanf("%d ", &tt);
  for (int ii = 0; ii < tt; ii++) {
    int t;
    scanf("%d ", &t);
    left.clear(); right.clear();
    int cur = 1;
    while (t != 0) {
      if (t % 3 == 1) {
        right.push_back(cur);
      } else if (t % 3 == 2) {
        left.push_back(cur);
        t++;
      }

      t /= 3;
      cur *= 3;
    }
    printf("left pan:");
    for (int i = left.size() - 1; i >= 0; i--) {
      printf(" %d", left[i]);
    }
    printf("\nright pan:");
    for (int i = right.size() - 1; i >= 0; i--) {
      printf(" %d", right[i]);
    }
    printf("\n");
    if (ii != tt - 1) {
      printf("\n");
    }
  }
  return 0;
}
