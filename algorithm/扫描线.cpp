// #pragma clang diagnostic ignored "-Wdeprecated-declarations"
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

// const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int n;

struct node {
  int x1, x2, y, v;
  node () {}
  node (int a, int b, int c, int d) : x1(a), x2(b), y(c), v(d) {};

  bool operator < (const node x) {
    return y < x.y;  
  }
} line[maxn * 2];

struct tree {
  int l, r, cover;
  ll len;
} t[maxn << 3];

int v[maxn * 2];

void pushup (int k) {
  if (t[k].cover) {
    t[k].len = t[k].r - t[k].l;
  }
  else t[k].len = t[k * 2].len + t[k * 2 + 1].len; 
}

void build (int k, int l, int r) {
  t[k].l = v[l];
  t[k].r = v[r];
  if (r - l <= 1) return;
  int m = (l + r) / 2;
  build(k * 2, l, m);
  build(k * 2 + 1, m, r);
}

void upd (int k, int l, int r, int v) {
  if (t[k].l >= l && t[k].r <= r) {
    t[k].cover += v;
    pushup(k);
    return;
  }
  if (l < t[k * 2].r) upd(k * 2, l, r, v);
  if (r > t[k * 2 + 1].l) upd(k * 2 + 1, l, r, v);
  pushup(k);
}



int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b , c, d;
    cin >> a >> b >> c >> d;
    line[i] = node (a, c, b, 1);
    line[i + n] = node (a, c, d, -1);
    v[i] = a;
    v[i + n] = c;
  }
  sort(v + 1, v + 1 + 2 * n);
  sort(line + 1, line + 1 + 2 * n);
  build(1, 1, 2 * n);
  ll ans = 0;
  for (int i = 1; i <= 2 * n; i++) {
    ans += t[1].len * (line[i].y - line[i - 1].y);
    upd(1, line[i].x1 , line[i].x2, line[i].v);
  }
  cout << ans << endl;

  return 0;
}