#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll qp (ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}

ll base[505][505];

ll ans[505][505];

ll now[505][505];
int n;
ll k, a, b, c;

ll tmp[505][505];

void mul(ll a[][505], ll b[][505]) {
  for (int i = 1; i <= n; i++) tmp[1][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      tmp[1][i] = (tmp[1][i] + a[1][j] * b[j][i] % mod) % mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[1][i] = tmp[1][i];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int p = j == 1 ? n : j - 1;
      a[i][j] = a[i - 1][p];
    }
  }
}

void solve () {
  for (int i = 1; i <= n; i++) now[i][i] = 1;
  while (k) {
    if (k & 1) mul(now, base);
    mul(base, base);
    k >>= 1;
  }
}

int main () {
  cin >> n >> k;
  cin >> a >> b >> c;
  ll sum = a + b + c;
  sum = qp(sum, mod - 2);
  a = a * sum % mod;
  b = b * sum % mod;
  c = c * sum % mod;

  for (int i = 1; i <= n; i++) {
    cin >> ans[1][i];
  }

  for (int i = 1; i <= n; i++) {
    base[i][i] = c;
    int u = i == 1 ? n : i - 1;
    int d = i == n ? 1 : i + 1;
    base[u][i] = a;
    base[d][i] = b;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << base[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  solve();
  mul(ans, now);
  for (int i = 1; i <= n; i++) {
    cout << ans[1][i] << " ";
  }
  
  cout << endl;

  
  



  return 0;
}