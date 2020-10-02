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
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll qp(ll a, ll b, ll mod) {
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

namespace NTT {

const int mod = 998244353;

const int g = 3;
typedef long long ll;
void rader(ll *a, int len) {
  int j = len / 2;
  for (int i = 1; i < len - 1; i++) {
    if (i < j)
      swap(a[i], a[j]);
    int k = len / 2;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k)
      j += k;
  }
}

ll qp(ll a, ll b) {
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

void ntt(ll f[], int len, int rev) {
  rader(f, len);
  for (int mid = 1; mid < len; mid *= 2) {
    ll tmp = qp(g, (mod - 1) / (2 * mid));
    if (rev == -1)
      tmp = qp(tmp, mod - 2);

    for (int i = 0; i < len; i += mid * 2) {
      ll omega = 1;
      for (int j = 0; j < mid; j++, omega = omega * tmp % mod) {
        ll x = f[i + j], y = omega * f[i + j + mid] % mod;
        f[i + j] = (x + y) % mod;
        f[i + j + mid] = (x - y + mod) % mod;
      }
    }
  }
  ll inv = qp(len, mod - 2);
  if (rev == -1) {
    for (int i = 0; i < len; i++) {
      f[i] = f[i] * inv % mod;
    }
  }
}

} // namespace NTT

ll a[(1 << 22) + 5], b[(1 << 22) + 5];

int getphi(int x) {
  int ans = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans = ans / i * (i - 1);
      while(x % i == 0) x /= i;
    }
  }
  if (x != 1) ans = ans / x * (x - 1);
  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;

  ll n2 = qp(n, n, k - 1) + k - 1;
  ll n3 = qp(n, qp(n, n, getphi(k - 1)) + getphi(k - 1), k - 1) + k - 1;

  // cout << n << " " << n2 << " " << n3 << endl;

  for (int i = 1; i <= n; i++) {
    ll x = qp(i, n, k);
    ll y = qp(i, n2, k);
    a[x]++;
    b[y]++;
  }

  // for (int i = 0; i < k ;i++) {
  //   cout << a[i] << " " << b[i] << endl;
  // }

  NTT::ntt(a, 1 << 21, 1);
  NTT::ntt(b, 1 << 21, 1);

  for (int i = 0; i < 1 << 21; i++) {
    a[i] = a[i] * b[i] % mod;
  }

  NTT::ntt(a, 1 << 21, -1);

  for (int i = k; i < 1 << 21; i++) {
    a[i % k] =  (a[i % k] + a[i]) % mod;
  }
  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    ll x = qp(i, n3, k);
    ans = (ans + a[x]) % mod;
  }
  ans = (ans % mod + mod) % mod;

  cout << ans << endl;

  return 0;
}