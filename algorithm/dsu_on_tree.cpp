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

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n;

int val[maxn];

vector<int>  e[maxn];

int siz[maxn], son[maxn];

vector<int> v[maxn];

void init () {
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      v[j].push_back(i);
    }
  }
  for (int i = 1; i < maxn; i++) {
    reverse(v[i].begin(), v[i].end());
  }
}

void dfs1 (int now, int fa) {
  int ma = 0;
  siz[now] = 1;
  for (auto i : e[now]) {
    if (i != fa) {
      dfs1(i, now);
      siz[now] += siz[i];
      if (siz[i] > ma) {
        ma = siz[i];
        son[now] = i;
      }
    }
  }
}

map<int, int> cnt;

int ma[maxn], ans[maxn];

void query(int val, int rt) {
  for (auto i : v[val]) {
    if (i < ma[rt]) break;
    if (cnt[i]) {
      if (i == ma[rt]) ans[rt] += cnt[i];
      else if (i > ma[rt]) ma[rt] = i, ans[rt] = cnt[i];
      break;
    }
  }
}

void insert(int x) {
  for (auto i : v[x]) {
    cnt[i]++;
  }
}

void add (int x, int fa) {
  insert(val[x]);
  for (auto to : e[x]) {
    if (to != fa) add(to, x);
  }
}




void cal(int now, int fa, int rt) {
  query(val[now], rt);
  for (auto to : e[now]) {
    if (to != fa) {
      cal(to, now, rt);
    }
  }
  
}

void dfs2(int now, int fa) {
  for (auto to : e[now]) {
    if (to != fa && to != son[now]) {
      dfs2(to, now);
    }
  }

  if (son[now]) {
    dfs2(son[now], now);
  }

  for (auto to : e[now]) {
    if (to != fa && to != son[now]) {
      cal(to, now, now);
      add(to, now);
    }
  }
  query(val[now], now);
  insert(val[now]);
  if (son[fa] != now) {
    cnt.clear();
  }
}


int main () {

  init();
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  
  

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  dfs1(1, 1);
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ma[i] << " " << ans[i] << endl;
  }

}