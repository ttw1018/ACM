#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

// const int mod = 1e9 + 7;
// const int mod = 998244353;

const int maxn = 1e5 + 5;

int a[maxn];

bool can[maxn];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int ma = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    int sor = 1;
    for (int i = n; i >= 1; i--) {
      if (a[i] != i) {
        sor = i;
        break;
      }
    }

    double ans = 1;
    while (m--) {
      int x;
      double p;
      cin >> x >> p;
      if (x >= sor)
        ans *= (1 - p);
    }

    if (sor == 1) {
      printf("%.6f\n", double(1));
      continue;
    }

    printf("%.6f\n", 1 - ans);
  }
  return 0;
}
