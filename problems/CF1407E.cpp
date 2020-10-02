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
const int maxn = 5e5 + 5;

vector<int> v1[maxn], v2[maxn];

int w[maxn], b[maxn], d[maxn];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
      continue;

    if (c == 0) {
      v1[b].push_back(a);
    } else {
      v2[b].push_back(a);
    }
  }

  queue<int> q;

  for (int i = 1; i <= n; i++) {
    w[i] = b[i] = d[i] = n;
  }

  w[n] = b[n] = d[n] = 0;
  q.push(n);

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto i : v1[now]) {
      if (w[i] < n) {
        continue;
      }
      w[i] = d[now] + 1;
      if (max(w[i], b[i]) < n) {
        q.push(i);
        d[i] = max(w[i], b[i]);
      }
    }

    for (auto i : v2[now]) {
      if (b[i] < n) continue;
      b[i] = d[now] + 1;
      if (max(b[i], w[i]) < n) {
        d[i] = max(b[i], w[i]);
        q.push(i);
      }
    }
  }
  if (d[1] == n) {
    cout << -1 << endl;
  }
  else {
    cout << d[1] << endl;
  }
  for (int i = 1; i <= n; i++) {
    if (w[i] > b[i]) cout << "0";
    else cout << "1";
  }
  cout << endl;

  return 0;
}