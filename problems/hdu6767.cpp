/**
  * @Problem hdu6767.cpp
  * @Time 2020/7/28 21:02
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

const int maxn = 1e5;

struct edge {
    int from, to, flow;
    ll cost;

    edge(int a = 0, int b = 0, int c = 0, ll d = 0) : from(a), to(b), flow(c), cost(d) {}
} e[maxn];

int head[3000], tot = 1;

void add(int x, int y, ll cost) {
    e[++tot] = edge(head[x], y, 1, cost);
    head[x] = tot;
    e[++tot] = edge(head[y], x, 0, -cost);
    head[y] = tot;
}


int n, m, s, t, len;
ll a[55], b[55];
ll c[55];

vector<pair<int, int>> v;


void solve(int s, int a, int b) {
    if (b >= 0) {
        for (int i = 1; i <= n; i++) {
            v.push_back(make_pair(s, i));
        }
        return;
    }

    b = -b;
    double mid = 1.0 * b / (2 * a);

    int l = floor(mid);
    int r = ceil(mid);
    if (l == r) l--;
    int cnt = 0;
    while (l >= 1 && r <= m && cnt < n) {
        double dl = mid - l;
        double dr = r - mid;
        if (dl < dr) {
            v.push_back(make_pair(s, l));
            l--;
        } else {
            v.push_back(make_pair(s, r));
            r++;
        }
        cnt++;
    }

    if (l < 1) {
        while (cnt < n) {
            v.push_back(make_pair(s, r++));
            cnt++;
        }
    }

    if (r > m) {
        while (cnt < n) {
            cnt++;
            v.push_back(make_pair(s, l--));
        }
    }
//    cout << r - l << endl;
}

void add_edge() {
    vector<int> p;
    for (auto i : v) {
        p.push_back(i.second);
    }
    sort(p.begin(), p.end());
    len = unique(p.begin(), p.end()) - p.begin();
    s = len + n + 1;
    t = len + n + 2;

    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        ll cost = a[x] * y * y + b[x] * y + c[x];
        add(x, n + lower_bound(p.begin(), p.begin() + len, y) - p.begin() + 1, cost);
    }
    for (int i = 1; i <= n; i++) {
        add(s, i, 0);
    }
    for (int i = n + 1; i <= n + len; i++) {
        add(i, t, 0);
    }
}

int vis[3000], flow[3000], pre[3000], last[3000];
ll cost[3000];

bool spfa(int s, int t) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= t; i++) {
        cost[i] = 1e18;
        flow[i] = 1e9;
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

void mcmf() {
    ll mincost = 0;
    ll maxflow = 0;
    while (spfa(s, t)) {
        int now = t;
        mincost += cost[t];
        maxflow += flow[t];
        while (now != s) {
            e[last[now]].flow -= flow[t];
            e[last[now] ^ 1].flow += flow[t];
            now = pre[now];
        }
        cout << mincost;

        if (maxflow == n) {
            cout << endl;
        } else {
            cout << " ";
        }

    }

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        v.clear();
        tot = 1;
        memset(head, 0, sizeof(head));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            solve(i, a[i], b[i]);
        }
        add_edge();
        mcmf();

    }


    return 0;
}


