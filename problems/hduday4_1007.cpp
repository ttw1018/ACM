/**
  * @Problem hduday4_1007.cpp
  * @Time 2020/7/30 13:55
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

int n, s, t;

const int maxn = 2e5 + 5;

struct edge {
    int from, to, flow;
    int cost;

    edge(int a = 0, int b = 0, int c = 0, int d = 0) : from(a), to(b), flow(c), cost(d) {}
} e[maxn * 2];

int head[maxn], tot = 1;

void add(int x, int y, int flow, int cost) {
//    cout << x << " " << y << " " << flow << " " << cost << endl;
    e[++tot] = edge(head[x], y, flow, cost);
    head[x] = tot;
    e[++tot] = edge(head[y], x, 0, -cost);
    head[y] = tot;
}

int vis[maxn], flow[maxn], pre[maxn], last[maxn];
int cost[maxn];

bool spfa(int s, int t) {
    for (int i = 1; i <= t; i++) {
        cost[i] = 1e9;
        flow[i] = 1e9;
        vis[i] = 0;
    }
    queue<int> q;
    q.push(s);
    vis[s] = 1, cost[s] = 0, pre[t] = -1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int i = head[now]; i; i = e[i].from) {
            if (e[i].flow > 0 && cost[e[i].to] > cost[now] + e[i].cost) {
                cost[e[i].to] = cost[now] + e[i].cost;
                pre[e[i].to] = now;
                last[e[i].to] = i;
                flow[e[i].to] = min(flow[now], e[i].flow);
                if (!vis[e[i].to]) {
                    vis[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
        }
    }

    return pre[t] != -1;
}

int have[maxn];

void mcmf() {
//    ll mincost = 0;
    ll maxflow = 0;
    for (int i = 1; i < s - n; i++) {
        have[i] = 0;
    }
    int mincost = 0;

    while (spfa(s, t)) {
        int now = t;
        have[pre[now] - n] = 1;
        mincost += cost[t];
        maxflow += flow[t];
        e[last[t]].cost = 0;
        e[last[t] ^ 1].cost = 0;

        while (now != s) {
            e[last[now]].flow -= flow[t];
            e[last[now] ^ 1].flow += flow[t];
            now = pre[now];
        }
//        cout << maxflow << endl;
    }
//    cout << maxflow << " " << mincost << endl;
//    int ans = 0;
//    for (int i = 1; i < s - n; i++) {
//        if (have[i]) ans++;
//
//    }
//    printf("%d\n", ans);
    cout << mincost << endl;

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        map<int, pair<int, int>> w;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            w[i] = make_pair(a + b, a - b);
            v.push_back(a + b);
            v.push_back(a - b);
        }
        sort(v.begin(), v.end());
        int len = unique(v.begin(), v.end()) - v.begin();
        s = n + len + 1;
        t = s + 1;

        for (int i = 1; i <= t; i++) {
            head[i] = 0;
        }
        tot = 1;

        for (auto i : w) {
            int a = i.second.first;
            int b = i.second.second;
            int p1 = lower_bound(v.begin(), v.begin() + len, a) - v.begin() + 1;
            int p2 = lower_bound(v.begin(), v.begin() + len, b) - v.begin() + 1;
            add(i.first, p1 + n, 1, 0);
            add(i.first, p2 + n, 1, 0);
        }
        for (int i = 1; i <= n; i++) {
            add(s, i, 1, 0);
        }
        for (int i = n + 1; i < s; i++) {
            add(i, t, n, 1);
        }
        mcmf();

    }

    return 0;
}


