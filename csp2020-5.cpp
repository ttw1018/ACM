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

const int mod = 1e9 + 7;
// const int mod = 998244353;

const int maxn = 1e6 + 5;

struct node {
  ll l, r;
  ll x, y, z, ax, ay, az;
  ll m;
  void MOD() {
    x %= mod;
    y %= mod;
    z %= mod;
    ax %= mod;
    ay %= mod;
    az %= mod;
    m %= mod;
  }
} t[maxn * 4];

void build(int k, int l, int r) {
  t[k].l = l;
  t[k].r = r;
  t[k].m = 1;
  if (l == r)
    return;

  int m = (l + r) >> 1;
  build(k * 2, l, m);
  build(k * 2 + 1, m + 1, r);
}

void down(int k) {
  t[k * 2].MOD();
  t[k * 2 + 1].MOD();
  t[k].MOD();
  if (t[k].ax) {
    t[k * 2].ax += t[k].ax;
    t[k * 2 + 1].ax += t[k].ax;
    t[k * 2].x += t[k].ax * (t[k * 2].r - t[k * 2].l + 1);
    t[k * 2 + 1].x += t[k].ax * (t[k * 2 + 1].r - t[k * 2 + 1].l + 1);
    t[k].ax = 0;
  }
  if (t[k].ay) {
    t[k * 2].ay += t[k].ay;
    t[k * 2 + 1].ay += t[k].ay;
    t[k * 2].y += t[k].ay * (t[k * 2].r - t[k * 2].l + 1);
    t[k * 2 + 1].y += t[k].ay * (t[k * 2 + 1].r - t[k * 2 + 1].l + 1);
    t[k].ay = 0;
  }
  if (t[k].az) {
    t[k * 2].az += t[k].az;
    t[k * 2 + 1].az += t[k].az;
    t[k * 2].z += t[k].az * (t[k * 2].r - t[k * 2].l + 1);
    t[k * 2 + 1].z += t[k].az * (t[k * 2 + 1].r - t[k * 2 + 1].l + 1);
    t[k].az = 0;
  }
  if (t[k].m > 1) {
    t[k * 2].m *= t[k].m;
    t[k * 2 + 1].m *= t[k].m;
    t[k * 2].x *= t[k].m;
    t[k * 2].y *= t[k].m;
    t[k * 2].z *= t[k].m;

    t[k * 2 + 1].x *= t[k].m;
    t[k * 2 + 1].y *= t[k].m;
    t[k * 2 + 1].z *= t[k].m;
    t[k].m = 1;
  }
  t[k * 2].MOD();
  t[k * 2 + 1].MOD();
  t[k].MOD();
}

void push(int k) {
  t[k].x = (t[k * 2].x + t[k * 2 + 1].x) % mod;
  t[k].y = (t[k * 2].y + t[k * 2 + 1].y) % mod;
  t[k].z = (t[k * 2].z + t[k * 2 + 1].z) % mod;
  t[k].MOD();
}

void add(int k, int l, int r, ll x, ll y, ll z) {
  if (t[k].l >= l && t[k].r <= r) {
    t[k].x += x * (t[k].r - t[k].l + 1);
    t[k].y += y * (t[k].r - t[k].l + 1);
    t[k].z += z * (t[k].r - t[k].l + 1);
    t[k].ax += x;
    t[k].ay += y;
    t[k].az += z;
    return;
  }
  down(k);
  int m = (t[k].l + t[k].r) / 2;
  if (l <= m)
    add(k * 2, l, r, x, y, z);
  if (r > m)
    add(k * 2 + 1, l, r, x, y, z);
  push(k);
  t[k].MOD();
}

void mul(int k, int l, int r, ll m) {
  if (t[k].l >= l && t[k].r <= r) {
    t[k].m *= m;
    t[k].x *= m;
    t[k].y *= m;
    t[k].z *= m;
    t[k].MOD();
    return;
  }
  down(k);
  int mid = (t[k].l + t[k].r) / 2;
  if (l <= mid) {
    mul(k * 2, l, r, m);
  }
  if (r > mid) {
    mul(k * 2 + 1, l, r, m);
  }
  push(k);
  t[k].MOD();
}

vector<ll> que(int k, int l, int r) {
  vector<ll> ans(3, 0);
  if (t[k].l >= l && t[k].r <= r) {
    ans[0] = t[k].x;
    ans[1] = t[k].y;
    ans[2] = t[k].z;
    return ans;
  }
  down(k);
  int m = (t[k].l + t[k].r) / 2;
  if (l <= m) {
    vector<ll> now;
    now = que(k * 2, l, r);
    ans[0] += now[0];
    ans[1] += now[1];
    ans[2] += now[2];
  }
  if (r > m) {
    vector<ll> now;
    now = que(k * 2 + 1, l, r);
    ans[0] += now[0];
    ans[1] += now[1];
    ans[2] += now[2];
  }
  push(k);
  ans[0] %= mod;
  ans[1] %= mod;
  ans[2] %= mod;
  return ans;
}

ll a[100], b[100], c[100];

int main() {
  int n;
  cin >> n;
  build(1, 1, n);
  int m;
  cin >> m;
  while (m--) {
    int ope;
    cin >> ope;
    if (ope == 1) {
      ll x, y, z;
      int l, r;
      cin >> l >> r;
      cin >> x >> y >> z;
      add(1, l, r, x, y, z);
      // for (int i = l; i <= r; i++) {
      //   a[i] += x;
      //   b[i] += y;
      //   c[i] += z;
      //   a[i] %= mod;
      //   b[i] %= mod;
      //   c[i] %= mod;
      // }
    } else if (ope == 4) {
      int l, r;
      cin >> l >> r;
      vector<ll> ans;
      ans = que(1, l, r);
      ll val =
          ans[0] * ans[0] % mod + ans[1] * ans[1] % mod + ans[2] * ans[2] % mod;
      val %= mod;
      cout << val << endl;

      // ll x = 0, y = 0, z = 0;
      // for (int i = l; i <= r; i++) {
      //   x = (x + a[i]) % mod;
      //   y = (y + b[i]) % mod;
      //   z = (z + c[i]) % mod;
      // }
      // cout << (x * x % mod + y * y % mod + z * z % mod) % mod << endl;
    } else if (ope == 2) {
      int l, r;
      cin >> l >> r;
      ll m;
      cin >> m;
      m %= mod;
      mul(1, l, r, m);

      // for (int i = l; i <= r; i++) {
      //   a[i] = a[i] * m % mod;
      //   b[i] = b[i] * m % mod;
      //   c[i] = c[i] * m % mod;
      // }
    }
  }
  return 0;
}
