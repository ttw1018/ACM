#include <ios>
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

const int mod1 = 998244353;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

ll a[maxn], b[maxn], c[maxn], inv[maxn];
char s[maxn];
int n;

ll qp (ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}


void init() {
  inv[1] = qp(mod1, mod - 2);
  c[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    inv[i] = inv[i - 1] * inv[1] % mod;
    c[i] = c[i - 1] * mod1 % mod;
  }

  for (int i = 1; i <= n; i++) {
    a[i] = (a[i - 1] + (s[i] - 'a') * c[i - 1] % mod) % mod;
  }

  for (int i = n; i >= 1; i--) {
    b[i] = (b[i + 1] + (s[i] - 'a') * c[n - i] % mod) % mod;
  }
}

bool check (int l, int r) {
  ll x = (a[r] - a[l - 1] + mod) * inv[l - 1] % mod;
  ll y = (b[l] - b[r + 1] + mod) * inv[n - r] % mod;
  return x == y;
}


int dp[maxn], pre[maxn];

int main () {
  ios_base::sync_with_stdio(0);
  cin >> (s + 1);
  n = strlen(s + 1);
  init();
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    if (!check(1, i)) {
      dp[i] = 1;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (!check(j, i) && dp[j - 1] > 0) {
        dp[i] = dp[j - 1] + 1;
        pre[i] = j - 1;
        break;
      }
    }
  }
  cout << dp[n] << endl;
  if (dp[n] == -1) return 0;

  int now = n;
  vector<int> v;

  while (now) {
    v.push_back(now);
    now = pre[now];
  }
  v.push_back(0);

  reverse(v.begin(), v.end());

  for (int i = 1; i < v.size(); i++) {
    int l = v[i - 1], r = v[i];
    for (l++; l <= r; l++) {
      cout << s[l];
    }
    cout << endl;
  }
  cout << endl;


  
  


  return 0;
}