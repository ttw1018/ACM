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

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 5;

struct edge {
  int a, b, v;
  void in () {
    cin >> a >> b >> v;
  }
  bool operator < (edge a) {
    return v > a.v;
  }
} e[maxn];


set<int> w[maxn];
int fa[maxn];

int find (int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int uni (int x, int y) {
  int cnt = 0;
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    if (w[fx].size() < w[fy].size()) swap(fx, fy);
    fa[fy] = fx;
    return 1;
    for (auto i : w[fy]) {
      if (w[fx].find(i + 1) != w[fx].end()) cnt++;
      if (w[fx].find(i - 1) != w[fx].end()) cnt++;
    }
    for (auto i : w[fy]) {
      w[fx].insert(i);
    }
  }
  return cnt;
}


int main () {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    w[i].insert(i);
  }
  for (int i = 1; i <= m; i++) {
    e[i].in();
  }
  sort(e + 1, e + 1 + m);
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += ll(e[i].v) * ll(uni(e[i].a, e[i].b));
    
  }
  cout << ans << endl;
  



  return 0;
}