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

// const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int val[maxn];

int n, m;

vector<int> e[maxn], v[maxn];

int dep[maxn], fa[maxn][22];
int id[maxn];
int cnt;
int L[maxn], R[maxn], pos[maxn];

void dfs(int x, int fath) {
  dep[x] = dep[fath] + 1;
  fa[x][0] = fath;
  L[x] = ++cnt;
  pos[cnt] = x;
  v[dep[x]].push_back(cnt);
  for (int i = 1; i < 20; i++) {
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  for (auto to : e[x]) {
    if (to != fath) {
      dfs(to, x);
    }
  }
  R[x] = cnt;
}

struct node {
  int l, r, cnt;
  node(int l = 0, int r = 0, int cnt = 0) : l(l), r(r), cnt(cnt) {}
} t[maxn * 21];

int root[maxn];
int tot;

void build(int &now, int l, int r) {
  now = ++tot;
  t[now] = node(l, r, 0);
  if (l >= r)
    return;
  int mid = (l + r) >> 1;
  build(t[now].l, l, mid);
  build(t[now].r, mid + 1, r);
}

void insert(int l, int r, int pre, int &now, int x) {
  t[++tot] = t[pre];
  now = tot;
  t[now].cnt++;
  int m = (l + r) / 2;
  if (l < r) {
    if (x <= m) {
      insert(l, m, t[pre].l, t[now].l, x);
    } else {
      insert(m + 1, r, t[pre].r, t[now].r, x);
    }
  }
}

int query(int l, int r, int now, int pre, int k) {
  if (l == r)
    return l;
  int m = (l + r) / 2;
  int all = t[t[now].l].cnt - t[t[pre].l].cnt;
  if (k <= all)
    return query(l, m, t[now].l, t[pre].l, k);
  else
    return query(m + 1, r, t[now].r, t[pre].r, k - all);
}

int get(int a, int k) {
  int now = a;
  for (int i = 0; i < 20; i++) {
    if (k & (1 << i)) {
      now = fa[now][i];
    }
  }
  return now;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> val[i];

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  dfs(1, 0);
  // build(root[0], 1, n);
  
  // build(root[0], 1, 1000000);
  int cnt = 0;
  for (int i = 1; i <= 1000000; i++) {
    for (auto j : v[i]) {
      cnt++;
      id[j] = cnt;
      insert(1, n, root[cnt - 1], root[cnt], val[pos[j]]);
      // cout << val[j] << " ";
      // cout << j << " ";
    }
    // cout << endl;
  }
  // for (int i = 1; i <= 1000000; i++) {
  //   insert(1, 1000000, root[cnt - 1], root[cnt], 1);
  // }
  // cout << tot << endl;

  // for (int i = 1; i <= n; i++) {
  //   for (auto j : v[i]) cout << j << " ";
  //   cout << endl;
  // }
  int last = 0;
  while (m--) {
    int a, k;
    cin >> a >> k;
    a = (last ^ a) % n + 1;
    // cout << "a: " << a << " " << "k: " << k << endl;
    int acenstor = get(a, k);
    if (acenstor == 0) {
      cout << "?" << endl;
      continue;
    }

    int l = lower_bound(v[dep[a]].begin(), v[dep[a]].end(), L[acenstor]) - v[dep[a]].begin();
    int r = upper_bound(v[dep[a]].begin(), v[dep[a]].end(), R[acenstor]) - v[dep[a]].begin() - 1;
    // cout << l << " " << r << endl;


    if (r - l + 1 < k) {
      cout << "?" << endl;
      continue;
    }

    last = query(1, n, root[id[v[dep[a]][r]]], root[id[v[dep[a]][l]] - 1], k);

    cout << last << endl;
  }

  return 0;
}