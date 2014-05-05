#include <iostream>
#include <string>

#include <string.h>

using namespace std;

struct command {
  string a, b;
  int f,t;
};

#define struct command command

void out(int n, int** blocks, int* bl) {
  for(int i=0; i<n; ++i) {
    cout << i << ":";
    for(int j=0; j<bl[i]; ++j) {
      cout << " " << blocks[i][j];
    }
    cout << endl;
  }
}

int main() {
  int n;
  while(cin >> n) {
    int* blocks[n];
    int bl[n];
    memset(&bl, 0, n*sizeof(int));
    for(int i=0; i<n; ++i) {
      blocks[i] = new int(n);
      blocks[i][bl[i]++] = i;
    }

    while(true) {
      command c;
      cin >> c.a;
      if(c.a[0] == 'q') {
	out(n, blocks, bl);
	break;
      }

      cin >> c.f >> c.b >> c.t;
    }
  }
}
