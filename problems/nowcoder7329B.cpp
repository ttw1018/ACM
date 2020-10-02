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

ll a[maxn], sum[maxn];
bool cmp (int x, int y) { return x > y; }

int main () {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  ll ans = 0;
  
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      ans += sum[i * j];
    }
  }
  cout << ans << endl;



  return 0;
}