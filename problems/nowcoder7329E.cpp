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

// const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn];
int mil[maxn], mir[maxn], mal[maxn], mar[maxn];

int n;
int st[maxn];

vector<int> L[maxn], R[maxn], W[maxn];

int t[maxn];

int lowbit(int x) { return x & (-x); }

void upd(int x, int v) {
  while (x <= n) {
    t[x] += v;
    x += lowbit(x);
  }
}

int que(int x) {
  int ans = 0;
  while (x > 0) {
    ans += t[x];
    x -= lowbit(x);
  }
  return ans;
}

// struct node {
//   int l, r;
//   ll f, v;
// } t[maxn];

// #define ls k << 1
// #define rs k << 1 | 1
// void build (int k, int l, int r) {
//   t[k].l = l;
//   t[k].r = r;
//   if (l == r)  return;
//   int m = (l + r) >> 1;
//   build(ls, l, m);
//   build(rs, m + 1, r);
// }

// void push(int k) {
//   t[k].v = t[ls].v + t[rs].v;
// }

// void down(int k) {
//   t[ls].f += t[k].f;
//   t[rs].f += t[k].f;
//   t[ls].v += t[k].f * (t[ls].r - t[ls].l + 1);
//   t[rs].v += t[k].f * (t[rs].r - t[rs].l + 1);
//   t[k].f = 0;
// }
//

// void upd (int k, int l, int r) {
//   if (t[k].l >= l && t[k].r <= r) {
//     t[k].v += (t[k].r - t[k].l + 1);
//     t[k].f++;
//     return;
//   }
//   down(k);
//   int m = (t[k].l + t[k].r) >> 1;
//   if (l <= m) upd(ls, l, r);
//   if (r > m) upd(rs, l, r);
//   push(k);
// }

// ll que (int k, int p) {
//   if (t[k].l == t[k].r) {
//     return t[k].v;
//   }
//   down(k);
//   int m = (t[k].r + t[k].l) >> 1;
//   ll ans;
//   if (p <= m) ans = que(ls, p);
//   else ans = que(rs, p);
//   push(k);
//   return ans;

// }

int main() {
  while(cin >> n) {
    for(int i = 1; i <= n; i++) {
      t[i] = 0;
    }
  for (int i = 1; i < 1; i++) {
    int a;
  }

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int now = 0;
  for (int i = 1; i <= n; i++) {
    while (now && a[st[now]] > a[i])
      now--;
    mil[i] = now ? st[now] + 1 : 1;
    st[++now] = i;
  }
  now = 0;
  for (int i = 1; i <= n; i++) {
    
    while (now && a[st[now]] < a[i])
      now--;
    mal[i] = now ? st[now] + 1 : 1;
    st[++now] = i;
  }

  now = 0;
  for (int i = n; i >= 1; i--) {
    while (now && a[st[now]] > a[i])
      now--;
    mir[i] = now ? st[now] - 1 : n;
    st[++now] = i;
  }

  now = 0;
  for (int i = n; i >= 1; i--) {
    while (now && a[st[now]] < a[i])
      now--;
    mar[i] = now ? st[now] - 1 : n;
    st[++now] = i;
  }

  for (int i = 1; i <= n; i++) {
    if (mil[i] <= a[i] && mir[i] >= a[i]) {
      L[mil[i]].push_back(a[i]);
      R[mir[i]].push_back(a[i]);
    }

    if (mal[i] <= a[i] && mar[i] >= a[i]) {
      W[a[i]].push_back(i);
    }
  }
  

  
  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << " " << mil[i] << " " << mir[i] << endl;
  // }
  // cout << endl;

  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << " " << mal[i] << " " << mar[i] << endl;
  // }
  // cout << endl;

  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for (auto j : L[i]) {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }

  // cout << endl;
  // cout << endl;
  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for (auto j : R[i]) {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for (auto j : W[i]) {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto j : L[i])
      upd(j, 1);
    for (auto j : W[i])
      ans += que(mar[j]) - que(mal[j] - 1);
    for (auto j : R[i])
      upd(j, -1);
    // cout << ans << endl;
  }
  cout << ans << endl;

  for (int i = 1; i <= n; i++) {
    L[i].clear();
    R[i].clear();
    W[i].clear();
  }
  //
  // cout << endl;
  // build(1, 1, n);

  // for (int i = 1; i <= n; i++) {
  //   if (a[i] >= mil[i] && a[i] <= mir[i]) {
  //     // cout << a[i] << " " << mir[i] << endl;
  //     upd(1, a[i], mir[i]);
  //   }
  // }

  // ll ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   if (mal[i] <= a[i] && mar[i] >= a[i]) {
  //     ans += que(1, a[i]);
  //     // cout << i << endl;
  //   }
  // }

  // cout << ans << endl;
  }

  return 0;
}