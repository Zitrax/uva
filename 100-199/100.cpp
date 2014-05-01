#include <iostream>
#include <vector>

using namespace std;

const int MAX_CACHE = 1000000;

int cycleLength(unsigned int n) {

  static int cache[MAX_CACHE] = {};
  if(cache[n] > 0) {
    return cache[n];
  }

  vector<unsigned int> path;
  path.push_back(n);

  while(n!=1) {
    if(n%2==1) {
      n = 3*n+1;
    } else {
      n /= 2;
    }
    path.push_back(n);
  }

  int size = path.size();
  for(int i=1; i<=size; ++i) {
    if(path[size-i] < MAX_CACHE) {
      cache[path[size-i]] = i;
    }
  }

  return path.size();
}

int maxLength(int i, int j) {
  if( i > j ) {
    swap(i,j);
  }
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
