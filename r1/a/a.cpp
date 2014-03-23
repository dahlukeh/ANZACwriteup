#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
using namespace std;

vector<string> words;
set<string> taken;

void proc() {
  words.clear();
  taken.clear();
  while(true) {
    char in[200];
    char c;
    scanf("%s%c", in, &c);
    words.push_back(string(in));
    if (c == '\n') {
      break;
    }
  }
  char in[500];
  while (true) {
    fgets(in, 500, stdin);
    if (strchr(in, '?')) {
      break;
    }
    char *sound = strchr(in, ' ');
    sound = strchr(sound + 1, ' ') + 1;
    if (strchr(sound, '\n')) {
      *(strchr(sound, '\n')) = 0;
    }
    taken.insert(string(sound));
  }

  int numPrinted = 0;
  for (int i = 0; i < words.size(); i++) {
    if (taken.count(words[i]) == 0) {
      if (numPrinted != 0) {
        printf(" ");
      }
      numPrinted++;
      printf("%s", words[i].c_str());
    }
  }
  printf("\n");
/*
  for (set<string>::iterator i = taken.begin(); i != taken.end(); i++) {
    printf("%s\n", (*i).c_str());
  }
  */
}

int main() {
  int t;
  scanf("%d ", &t);
  for (int i = 0; i < t; i++) {
    proc();
  }
  return 0;
}
