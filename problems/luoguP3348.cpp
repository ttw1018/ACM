/**
  * @Problem luoguP3348.cpp
  * @Time 2020/7/29 13:24
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int n, m, s, t;

struct Edge {
    int from, to, flow, cost;

    Edge(int a = 0, int b = 0, int c = 0, int d = 0) : from(a), to(b), flow(c), cost(d) {}
} e[maxn * 2];

int head[maxn], tot = 1;

void add(int x, int y, int f, int c) {
    e[++tot] = Edge(head[x], y, f, c);
    head[x] = tot;
    e[++tot] = Edge(head[y], x, 0, -c);
    head[y] = tot;
}

int vis[maxn], cost[maxn], flow[maxn];

int pre[maxn], last[maxn];


bool spfa(int s, int t) {
    memset(vis, 0, sizeof(vis));
    memset(flow, inf, sizeof(flow));
    memset(cost, inf, sizeof(cost));
    queue<int> q;
    q.push(s);
    vis[s] = 1, cost[s] = 0, pre[t] = -1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int i = head[now]; i; i = e[i].from) {
//            cout << e[i].to << " " << e[i].cost << endl;
            if (e[i].flow > 0 && cost[e[i].to] > cost[now] + e[i].cost) {
                cost[e[i].to] = cost[now] + e[i].cost;
                pre[e[i].to] = now;
                last[e[i].to] = i;
                flow[e[i].to] = min(flow[now], e[i].flow);
                if (!vis[e[i].to]) {
                    q.push(e[i].to);
                    vis[e[i].to] = 1;
                }
            }
        }
    }
    return pre[t] != -1;
}


void mcmf() {
    int maxflow = 0, mincost = 0;
    while (spfa(s, t)) {
        int now = t;
        maxflow += flow[t];
        mincost += flow[t] * cost[t];
        while (now != s) {
            e[last[now]].flow -= flow[t];
            e[last[now] ^ 1].flow += flow[t];
            now = pre[now];
        }
    }
    cout << maxflow << " " << mincost << endl;

}


int main() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int x, y, f, c;
        cin >> x >> y >> f >> c;
        add(x, y, f, c);
    }
    mcmf();


    return 0;
}
