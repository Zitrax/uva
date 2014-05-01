#include <iostream>

using namespace std;

int cycleLength(unsigned int n) {
  int i=0;
  while(n!=1) {
    if(n%2==1) {
      n = 3*n+1;
    } else {
      n /= 2;
    }
    ++i;
  }
  return i+1;
}

int maxLength(int i, int j) {
  int max = 0;
  for(int x=i; x<=j; ++x) {
    int m = cycleLength(x);
    if(m>max) {
      max = m;
    }
  }
  return max;
}

void output(int i, int j) {
  cout << i << " " << j << " " << maxLength(i,j) << endl;
}

int main() {
  int i,j;
  while(cin >> i) {
    cin >> j;
    output(i, j);
  } 
}
