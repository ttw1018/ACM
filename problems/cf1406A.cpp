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

int a[105];

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x; 
      a[x]++;
    }
    int ans = 0;
    for (int i = 0; i <= 101; i++) {
      if (a[i] == 0) {
        ans += i; 
        break;
      }
    }
    for (int i = 0; i <= 101; i++) {
      if (a[i] <= 1) {
        ans += i;
        break;
      }
    }
    cout << ans << endl;
    
    for (int i = 0; i <= 100; i++) a[i] = 0;
  }



  return 0;
}