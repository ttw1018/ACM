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
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2e6 + 5;

int a[maxn];
pair<int, int> p[maxn];
int vis[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  memset(vis, -1, sizeof(vis));
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i].first = a[i];
    p[i].second = i;
  }
  sort(p + 1, p + 1 + n);

  int now = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    int temp = 1;
    int val = p[i].first;
    // cout << p[i].first << " " << p[i].second << endl;
    if (vis[p[i].second] == p[i].first)
      continue;
    int l = p[i].second - 1;
    int r = p[i].second + 1;
    vis[p[i].second] = p[i].first;
    while (l > 0 && vis[l] != val) {
      if (a[l] % val == 0) {
        temp++;
        vis[l] = val;
        l--;
      } else {
        break;
      }
    }
    while (r <= n && vis[r] != val) {
      if (a[r] % val == 0) {
        temp++;
        vis[r] = val;
        r++;
      } else {
        break;
      }
    }
    if (temp == now) {
      cnt++;
    }
    if (temp > now) {
      now = temp;
      cnt = 1;
    }
  }
  cout << cnt << endl;

  return 0;
}