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

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;


int main () {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int ans = abs(n - k);
		int mi = k;
		ans = min(ans, abs(n - mi));
		if (n > mi) {
			n -= k;
			if (n & 1) {
				ans = min(1, ans);
			}
			else {
				ans = 0;
			}
		}
		cout << ans << endl;

	}



	return 0;
}