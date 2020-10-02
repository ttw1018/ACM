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
typedef long double ld;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;


int main () {
  int T;
  cin >> T;
  a:
  while (T--) {
      ll a, b, k;
      cin >> a >> b >> k;
      if (a > b) swap(a, b);
      ld x = (1 - k + sqrt(k * k + 2 * k + 5)) / 2;
      ld y = (3 + k + sqrt(k * k + 2 * k + 5)) / 2;

      ll n = a / x;
      for (int i = -4; i <= 4; i++) {
        if (ll(x * (n + i)) == a && ll(y * (n + i)) == b) {
          cout << 0 << endl;
          goto a;
        }
      }
      cout << 1 << endl;

  }



  return 0;
}