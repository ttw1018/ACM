/**
  * @Problem hdu6808.cpp
  * @Time 2020/7/31 13:13
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

vector<pair<int, int>> v;

vector<int> v1, v2;

const int maxn = 1e5 + 5;


struct edge {
    int from, to;

    edge(int a = 0, int b = 0) : from(a), to(b) {}
} e[maxn * 2];

int head[maxn], tot;

void add(int x, int y) {
    e[++tot] = edge(head[x], y);
    head[x] = tot;
}

int len1, len2;

int getid1(int x) {
    return lower_bound(v1.begin(), v1.begin() + len1, x) - v1.begin() + 1;
}

int getid2(int x) {
    return lower_bound(v2.begin(), v2.begin() + len2, x) - v2.begin() + 1;
}

void add_edge() {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    memset(head, 0, sizeof(head));
    tot = 0;
    len1 = unique(v1.begin(), v1.end()) - v1.begin();
    len2 = unique(v2.begin(), v2.end()) - v2.begin();

    for (auto i : v) {
        int a = getid1(i.first);
        int b = getid2(i.second);
        add(a, b);
    }
}

int mx[maxn], my[maxn], used[maxn], dx[maxn], dy[maxn];
int dis;

bool bfs() {
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    queue<int> q;
    dis = 1e9;
    for (int i = 1; i <= len1; i++) {
        if (mx[i] == -1) {
            q.push(i);
            dx[i] = 0;
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (dx[now] > dis) break;
        for (int i = head[now]; i; i = e[i].from) {
            int to = e[i].to;
            if (dy[to] == -1) {
                dy[to] = dx[now] + 1;
                if (my[to] == -1) dis = dy[to];
                else {
                    dx[my[to]] = dy[to] + 1;
                    q.push(my[to]);
                }
            }
        }
    }
    return dis != 1e9;
}

int dfs(int x) {
    for (int i = head[x]; i; i = e[i].from) {
        int to = e[i].to;
        if (!used[to] && dy[to] == dx[x] + 1) {
            used[to] = 1;
            if (my[to] != -1 && dy[to] == dis) continue;

            if (my[to] == -1 || dfs(my[to])) {
                my[to] = x;
                mx[x] = to;
                return true;
            }
        }
    }
    return false;

}

void hk() {
    int ans = 0;
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    while (bfs()) {
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= len1; i++) {
            if (mx[i] == -1 && dfs(i)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        v.clear();
        v1.clear();
        v2.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, t;
            cin >> x >> t;
            v.push_back(make_pair(x + t, x - t));
            v1.push_back(x + t);
            v2.push_back(x - t);
        }
        add_edge();
//        cout << len1 << " " << len2 << endl;
        hk();
    }
    return 0;
}
