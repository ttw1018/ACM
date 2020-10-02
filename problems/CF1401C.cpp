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

int a[maxn], b[maxn];

int main () {
	int T;
	cin >> T;
	a:
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a + 1, a + 1 + n);
		int now = a[1];
		for (int i = 1; i <= n; i++) {
			if (b[i] != a[i]) {
				if (b[i] % now) {
					cout << "NO" << endl;
					goto a;
				}
			}
		}
		cout << "YES" << endl;

	}



	return 0;
}