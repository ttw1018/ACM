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
const int maxn = 2e5 + 5;

ll a[maxn];




int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    ll ans = -1e18;
    ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]);
    ans = max(ans, a[0] * a[1] * a[n - 1] * a[n - 2] * a[n - 3]);
    ans = max(ans, a[0] * a[1] * a[2] * a[3] * a[n - 1]);
    cout << ans << endl;
    
  }
  



  return 0;
}