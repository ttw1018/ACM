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

int a[maxn];
int l[maxn], r[maxn];

int main () {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  l[0] = n;
  r[n + 1] = n;
  for (int i = 1; i <= n; i++) {
    l[i] = min(a[i], l[i - 1]);
  }
  for (int i = n; i >= 1; i--) {
    r[i] = min(r[i + 1], a[i]);
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << min(l[a - 1], r[b + 1]) << endl;
  }
  
  



  return 0;
}