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

vector<int>  v[maxn];

int n;
int ma[maxn], siz[maxn], son[maxn];
void dfs(int x, int fa) {
  siz[x] = 1;
  for (auto i : v[x]) {
    if (i != fa) {
      dfs(i, x);
      siz[x] += siz[i];
      if (siz[i] > ma[x]) {
        ma[x] = siz[i];
        son[x] = i;
      }
    }
  }
  if (n - siz[x] > ma[x]) {
    ma[x] = n - siz[x];
    son[x] = fa;
  }
}


int leaf;
void dfs1 (int x, int fa) {
  if (v[x].size() == 1) {
    leaf = x;
    cout << x << " " << fa << endl;
    return;
  }
  for (auto i : v[x]) {
    if (i != fa) {
      dfs1(i, x);
      return;
    }
  }
  
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(1, 0);
    int cnt = 0;
    int now = 1e5;
    int m = 1;
    for (int i = 1; i <= n; i++) {
      if (ma[i] < now) {
        now = ma[i];
        m = i;
        cnt = 1;
      }
      else if (ma[i] == now) cnt++;
    }

    if (cnt <= 1) {
      cout << 1 << " " << v[1][0] << endl;
      cout << 1 << " " <<  v[1][0] << endl;
    } 
    else {
      dfs1(son[m], m);
      cout << leaf << " " << m << endl;
    }
    
    for (int i = 1; i <= n; i++) {
      v[i].clear();
      siz[i] = 0;
      ma[i] = 0;
      son[i] = 0;
    }
  }



  return 0;
}