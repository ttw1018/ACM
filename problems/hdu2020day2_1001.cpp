/**
  * @Problem hdu2020day2_1001.cpp
  * @Time 2020/7/23 12:14
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
int val[maxn];


struct node {
    int from, to;

    node(int from = 0, int to = 0) : from(from), to(to) {}
} e[maxn * 4];


int head[maxn], tot;

void add(int x, int y) {
    e[++tot] = node(head[x], y);
    head[x] = tot;
    e[++tot] = node(head[y], x);
    head[y] = tot;
}

bool vis[maxn];
ll ans = 0;


void dfs(int now, int fa, int v) {
//	cout << now << endl;
    vis[now] = 1;

    if (val[now] > v) {
        ans += val[now] - v;
        v = val[now];
    } else if (val[now] < v) {
        v = val[now];
    }

    for (int i = head[now]; i; i = e[i].from) {
        int to = e[i].to;
        if (to != fa && !vis[to]) {
            dfs(to, now, v);
        }
    }
}

int main() {
    for (int i = 1; i <= 50; i++) {
        cout << i << " " << pow(50 / i, i - 50 % i) * pow(50 / i + 1, 50 % i) << endl;
    }
//	int T;
//    scanf("%d", &T);
//	while (T--) {
//		int n, m;
//		scanf("%d %d", &n, &m);
//
//		for (int i = 1; i <= n; i++) {
//			head[i] = 0;
//			vis[i] = 0;
//		}
//		tot = 0;
//		ans = 0;
//
//
//		for (int i = 1; i <= n; i++) {
//		    scanf("%d", &val[i]);
//		}
//
//		for (int i = 1; i <= m; i++) {
//			int a, b;
//			scanf("%d %d", &a, &b);
//			add(a, b);
//		}
//
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i]) {
//				dfs(i, 0, 0);
//			}
//		}
//		printf("%lld\n", ans);
//
//	}
//
//
    return 0;
}
