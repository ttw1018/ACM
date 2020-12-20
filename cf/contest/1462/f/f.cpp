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

const int maxn = 2e5 + 5;

struct node {
  int l, r;
} a[maxn];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v1, v2;

    for (int i = 1; i <= n; i++) {
      int l, r;
      cin >> l >> r;
      a[i].l = l;
      a[i].r = r;
      v1.push_back(l);
      v2.push_back(r);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = n - 1;
    for (int i = 1; i <= n; i++) {
      int l = a[i].l;
      int r = a[i].r;
      int k = lower_bound(v2.begin(), v2.end(), l) - v2.begin();
      int all = upper_bound(v1.begin(), v2.end(), l) - v1.begin();
    }
  }
  return 0;
}
