/**
  * @Problem hdu6797.cpp
  * @Time 2020/7/30 8:45
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

int n, k;

const int maxn = 1e5 + 5;

struct edge {
    int from, to, val, can;

    edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), val(c), can(1) {}
} e[maxn];

int head[55], tot;

void add(int x, int y, int w) {
    e[++tot] = edge(head[x], y, w);
    head[x] = tot;
    e[++tot] = edge(head[y], x, w);
    head[y] = tot;
}

int ans = 0;

void dfs(int k) {
    int dis[55], vis[55], pre[55], last[55];
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    dis[1] = 0;
    int now = 1;
    for (int i = 1; i < n; i++) {
        int val = 1e9;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < val) {
                val = dis[j];
                now = j;
            }
        }
        vis[now] = 1;
        if (now == n) {
            break;
        }
        for (int j = head[now]; j; j = e[j].from) {
            if (e[j].can && dis[e[j].to] > dis[now] + e[j].val) {
                dis[e[j].to] = dis[now] + e[j].val;
                pre[e[j].to] = now;
                last[e[j].to] = j;
            }
        }
    }

    if (k == 0) {
//        cout << dis[n] << endl;
        ans = max(ans, dis[n]);
        return;
    }


    now = n;
    while (now != 1) {
        e[last[now]].can = 0;
        e[last[now] ^ 1].can = 0;
        dfs(k - 1);
        e[last[now]].can = 1;
        e[last[now] ^ 1].can = 1;
        now = pre[now];
    }

}


int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(head, 0, sizeof(head));
        tot = 1;
        ans = 0;
        cin >> n >> k;
        int all = n * (n - 1) / 2;
        for (int i = 0; i < all; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
        }

        dfs(k);
        cout << ans << endl;


    }


    return 0;
}
