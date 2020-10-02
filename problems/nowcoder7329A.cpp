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


int main () {
  int n;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    double ans = t * 5.5;
    ans -= int(ans) / 360 * 360;
    if (ans > 180) ans = 360 - ans;

    cout << round(ans) << endl;


    
    
  }


  return 0;
}