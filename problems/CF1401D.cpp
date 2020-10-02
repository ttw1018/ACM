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

struct edge {
  int from, to;
  edge(int a = 0, int b = 0) : from(a), to(b) {}
} e[maxn * 2];
int tot, head[maxn];

void add(int x, int y) {
  e[++tot] = edge(head[x], y);
  head[x] = tot;
  e[++tot] = edge(head[y], x);
  head[y] = tot;
}

ll dp[maxn];

void dfs(int now, int fa) {
	dp[now] = 1;
	for (int i = head[now]; i; i = e[i].from) {
		int to = e[i].to;
		if (to == fa) continue;
		dfs(to, now);
		dp[now] += dp[to];
	}
}

ll val[maxn];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
		tot = 0;
		for (int i = 1; i <= n; i++) {
			head[i] = 0;
			dp[i] = 0;
		}
    for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;;
			add(a, b);
		}
		dfs(1, 0);
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> val[i];
		}
		sort(val + 1, val + 1 + m);

		vector<ll>	 v;
		for (int i = 2; i <= n; i++) {
			int now = dp[i];
			now = min(now, n - now);
			v.push_back(now);
		}
		sort(v.begin(), v.end());

		ll ans = 0;
		if (m <= n - 1) {
			for (int i = 1; i <= n - 1 - m; i++) {
				ans = (ans + v[i - 1] * (n - v[i - 1]) % mod) % mod;
			}
			
			for (int j = 1; j <= m; j++) {
				ans = (ans + v[n - 2 - m + j] * (n - v[n - 2 - m + j]) % mod * val[j]) % mod;
			}
		}
		else {
		
			for (int i = 1; i < n - 1; i++) {
				ans = (ans + v[i - 1] * (n - v[i - 1]) % mod * val[i] % mod) % mod;
			}
			
			ll now = v[n - 2] * (n - v[n - 2]) % mod;

			for (int i = n - 1; i <= m; i++) {
				now = now * val[i] % mod;
			}
			ans = (ans + now) % mod;
		}
		cout << ans << endl;
  }

  return 0;
}