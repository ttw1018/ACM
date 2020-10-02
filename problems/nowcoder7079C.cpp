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
  int u, v; 
  ll w;
  edge (int a = 0, int b = 0, ll c = 0) : u(a), v(b), w(c) {}
  bool operator < (const edge &e) {
    return w < e.w;
  }
} e[maxn];

int L[maxn];

int fa[maxn], siz[maxn];

unsigned int SA, SB, SC; int n, m, q, LIM;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

void gen(){
    scanf("%d%d%d%u%u%u%d", &n, &m, &q, &SA, &SB, &SC, &LIM);
    for(int i = 1; i <= m; i++){
        e[i].u = rng61() % n + 1;
        e[i].v = rng61() % n + 1;
        e[i].w = rng61() % LIM;
    }
    sort(e + 1, e + 1 + m);
    for(int i = 1; i <= q; i++){
        L[i] = rng61() % LIM;
    }
    sort(L + 1, L + q + 1);
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
      siz[i] = 1;
    }
}
int find (int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

ll ans = 0;
ll all = 0;
void add (int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    if (fx > fy) swap(fx, fy);
    fa[fy] = fx;
    all += ll(1) * siz[fx] * siz[fy];
    siz[fx] += siz[fy];
  }
}


int main () {
  gen();
  int now = 1;
  for (int i = 1; i <= q; i++) {
    for (; now <= m && e[now].w <= L[i]; now++) {
      add(e[now].u, e[now].v);
    }
    ans = ans ^ all;
  }
  cout << ans << endl;


  return 0;
}