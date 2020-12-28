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
const int mod = 998244353;

const int maxn = 205;

int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

ll qp(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int n;
int gauss() {
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++)
  //     cout << c[i][j] << " ";
  //   cout << endl;
  // }
  // cout << endl;
  int ans = 0;
  for (int k = 0, p = 0; k < n; k++) {
    int flag = 0;
    for (int i = p; i < n; i++) {
      if (c[i][k] == 1) {
        if (i != p)
          swap(c[i], c[p]);
        flag = 1;
      }
    }
    if (!flag) {
      ans++;
      continue;
    }
    for (int i = p + 1; i < n; i++) {
      if (!c[i][k])
        continue;
      for (int j = 0; j < n; j++) {
        c[i][j] ^= c[p][j];
      }
    }
    p++;
  }
  return ans;
}

int line_base() {
  bitset<200> d[200];
  memset(d, 0, sizeof(d));
  bool vis[200];
  memset(vis, 0, sizeof(vis));
  int ans = n;
  for (int k = 0; k < n; k++) {
    for (int i = n - 1; i >= 0; i--) {
      if (c[k][i]) {
        if (!vis[i]) {
          d[i] = c[k];
          ans--;
          vis[i] = 1;
          break;
        } else {
          c[k] = c[k] ^ d[i];
        }
      }
    }
  }

  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
    }
  }
  ll ans = 0;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[i][j] = a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      c[i][i] ^= b[i][k];
    }
    ans += gauss();
  }

  cout << qp(2, ans) << endl;

  return 0;
}