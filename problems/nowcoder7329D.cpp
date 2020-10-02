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
const int maxn = 5e5 + 5;

int a[maxn];

ll dp[2][maxn];
vector<int> v;

ll c[maxn], inv[maxn];

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

void init () {
  c[0] = c[1] = 1;
  for (int i = 2; i < maxn; i++) {
    c[i] = c[i - 1] * i % mod;
  }
  
  inv[0] = 1;
  inv[1] = 1;
  
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  for (int i = 2; i < maxn; i++) {
    inv[i] = inv[i - 1] * inv[i] % mod;
  }
  
}

ll get(int n, int m) {
  // return c[m] * c[n - m] % mod * inv[n] % mod;
  return c[n] * inv[m] % mod * inv[n - m] % mod;
}

int main () {
  init();

  int n, d;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);

  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[i - 1] >= d) {
      v.push_back(cnt);
      cnt = 1;
    }
    else {
      cnt++;
    }
  }
  v.push_back(cnt);
  
  sort(v.begin(), v.end());

  // for (auto i : v) {
  //   cout << i << " ";
  // }
  // cout << endl;
  
  dp[1][0] = 1;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j <= n; j++) {
      dp[i & 1][j] = 0;
    }
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= v[i]; k++) {
        if (j - k >= 0) {
          dp[i & 1][j] += dp[(i & 1) ^ 1][j - k];
          dp[i & 1][j] %= mod;
        }
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    // cout << dp[(v.size() - 1) & 1][i] << " " << get(n, i) << " ";
    cout << dp[(v.size() - 1) & 1][i] * qp(get(n, i), mod - 2) % mod << endl;
    // cout << dp[(v.size() - 1) & 1][i] << " ";
  }
  


  return 0;
}