#include <iostream>

using namespace std;

const int MAX_CACHE = 1000000;

int cycleLength(unsigned int n) {

  static int cache[MAX_CACHE] = {};
  if(cache[n] > 0) {
    return cache[n];
  }

  int p = 0;
  unsigned int path[525]; // max for 1 000 000
  path[p++] = n;

  while(n!=1) {

    if(n < MAX_CACHE && cache[n] > 0) {

      // Cache the path until we hit the cache
      for(int i=2; i<=p; ++i) {
	if(path[p-i] < MAX_CACHE) {
	  cache[path[p-i]] = i - 1 + cache[n];
	}
      }

      return p - 1 + cache[n];
    }

    if(n%2==1) {
      n = 3*n+1;
    } else {
      n /= 2;
    }
    path[p++] = n;
  }

  // Cache the whole path for future calls
  for(int i=1; i<=p; ++i) {
    if(path[p-i] < MAX_CACHE) {
      cache[path[p-i]] = i;
    }
  }

  return p;
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
