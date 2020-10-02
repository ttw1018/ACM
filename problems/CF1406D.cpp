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
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll a[maxn];

struct node {
  int l, r;
  ll  val, f;
  node (int a = 0, int b = 0, int c = 0, int d = 0) : l(a), r(b), val(c) , f(d){}
} t[maxn * 4];

void build (int k, int l, int r) {
  t[k] = node (l, r);
  if (l == r) {
    t[k].val = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(k * 2, l, m);
  build(k * 2 + 1, m + 1, r);
}

void down(int k) {
  t[k * 2].f += t[k].f;
  t[k * 2 + 1].f += t[k].f;
  t[k].f = 0;
}


void upd(int k, int l, int r, ll v) {
  if (t[k].l >= l && t[k].r <= r) {
    t[k].f += v;
    return;
  }
  down(k);
  int m = (t[k].l + t[k].r) / 2;
  if (l <= m) upd(k * 2, l, r, v);
  if (r > m) upd(k * 2 + 1, l, r, v);
}
ll que (int k, int p) {
  if (t[k].l >= p && t[k].r <= p) {
    return t[k].f + t[k].val;
  }
  down(k);
  int m = (t[k].l + t[k].r) / 2;
  if (p <= m) return que(k * 2, p);
  else return que(k * 2 + 1, p);
}

int main () {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  ll all = 0;
  for (int i = 2; i <= n; i++) {
    all += max(ll(0), a[i] - a[i - 1]);
  }
  build(1, 1, n);
  if (que(1, 1) + all >= 0)
    cout << (que(1, 1) + all + 1) / 2 << endl;
  else 
    cout << (que(1, 1) + all) / 2 << endl;
  
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    ll v;
    cin >> l >> r >> v;
    if (l > 1) {
      all -= max(ll(0), que(1, l) - que(1, l - 1));
    }
    if (r < n) {
      all -= max(ll(0), que(1, r + 1) - que(1, r));
    }
    upd(1, l, r, v);
    if (l > 1) {
      all += max(ll(0), que(1, l) - que(1, l - 1));
    }
    if (r < n) {
      all += max(ll(0), que(1, r + 1) - que(1, r));
    }
    if (que(1, 1) + all >= 0) 
      cout << (que(1, 1) + all + 1) / 2 << endl;
    else 
      cout << (que(1, 1) + all) / 2 << endl;
  }
  
  
  



  return 0;
}