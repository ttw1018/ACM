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

const int maxn = 1e6 + 5;

int a[maxn];

ll sum[maxn];

set<ll> w;
void dfs(int l, int r) {
  w.insert(sum[r] - sum[l - 1]);

  if (a[l] == a[r])
    return;

  int mid = (a[l] + a[r]) / 2;

  int p = upper_bound(a + l, a + r + 1, mid) - a;

  dfs(l, p - 1);
  dfs(p, r);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }

    w.clear();
    dfs(1, n);

    // for (auto i : w) {
    //   cout << i << " ";
    // }
    // cout << endl;

    while (q--) {
      ll x;
      cin >> x;
      if (w.find(x) != w.end()) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
