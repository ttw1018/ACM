#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// const int mod = 1e9 + 7;
// const int mod = 998244353
// const int maxn = 1e5 + 5;

int a[105];

void max_heap(int *a, int siz) {}

void heap_sort(int n) {
  for (int i = 2; i <= n; i++) {
    int now = a[i];
    swap(a[i], a[1]);
    max_heap(a, i);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 10; i++) {
    a[i] = rand() % 100;
  }

  heap_sort(10);

  return 0;
}
