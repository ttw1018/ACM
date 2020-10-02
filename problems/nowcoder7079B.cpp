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

//const int mod = 998244353;
const int mod = 199999;
const int maxn = 2e5 + 5;

int inv2;

ll qp(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}

ll sum2[maxn], sum3[maxn], sum[maxn];

void init() {
  sum[0] = 1;
  for (ll i = 1; i < maxn; i++) {
    sum2[i] = (sum2[i - 1] + i * i % mod) % mod;
    sum3[i] = (sum3[i - 1] + i * i % mod * i % mod) % mod;
    sum[i] = (sum2[i] + sum3[i]) % mod * inv2 * i % mod * sum[i - 1] % mod;
    // if (i < 10) cout << sum2[i] << " " << sum3[i] << " " << sum[i] << endl;
  }

  
}

int main () {
  inv2 = qp(2, mod - 2);
  init();
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s.length() > 6 || (s.length() == 6 && s[0] >= '2')) {
      cout << 0 << endl;
      continue;
    }
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
      n = n * 10 + s[i] - '0';
    }
    cout << sum[n] << endl;

    
    
  }



  return 0;
}