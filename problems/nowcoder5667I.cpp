/**
  * @Problem nowcoder5667I.cpp
  * @Time 2020/8/12 12:08
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 250005;

#define  mp make_pair

int n, m;

struct Edge {
    int from, to, cost;

    Edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), cost(c) {}
} e[maxn * 2];

int head[maxn], tot = 1;

void add(int x, int y, int cost) {
//    cout << x << " " << y << endl;
    e[++tot] = Edge(head[x], y, cost);
    head[x] = tot;
    e[++tot] = Edge(head[y], x, cost);
    head[y] = tot;
}


int getid(int x, int y) {
    return (x - 1) * n + y;
}

int st = 0;
int ed;


ll dis[maxn];
int vis[maxn];

void djistra() {
    for (int i = 0; i <= n * n + 1; i++) {
        dis[i] = -1;
        vis[i] = 0;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push(mp(0, st));
    dis[st] = 0;
    while (!q.empty()) {
        pair<ll, int> now = q.top();
        q.pop();
        int x = now.second;
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].from) {
            int to = e[i].to;
            if (dis[to] == -1 || dis[to] > dis[x] + e[i].cost) {
//                cout << to << endl;
                dis[to] = dis[x] + e[i].cost;
                q.push(mp(dis[to], to));
            }
        }
    }
}


int main() {
    cin >> n >> m;

    ed = n * n + 1;

    for (int i = 1; i <= m; i++) {
        int l, r, c;
        char d;
        cin >> l >> r >> d >> c;

        int a = getid(l, r);
        if (d == 'L') {
            if (r == n) add(a, ed, c);
            else {
                add(a, getid(l, r + 1), c);
            }
        } else {
            if (l == 1) add(st, a, c);
            else {
                add(a, getid(l - 1, r), c);
            }
        }
    }
    djistra();

    cout << dis[ed] << endl;


    return 0;
}
