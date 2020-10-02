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

// const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    ll ans = 0;
    ans = 2 * min(z1, y2);
		int a = min(z1, y2);
		z1 -= a;
		y2 -= a;
		
		a = min(z1, z2);
		z1 -= a;
		z2 -= a;

		a = min(x1, z2);
		x1 -= a;
		z2 -= a;

		ans -= 2 * z2;
		
		cout << ans << endl;

  }

  return 0;
}