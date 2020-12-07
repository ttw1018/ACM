//
// Created by ttw on 2020/11/18.
//


/**  * @Problem CF1440D.cpp
  * @Time 2020/11/17 23:37
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int T;
unordered_set<int> e[maxn];

int n, m, k;

int c[maxn];
int vis[maxn];

int fa[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int siz[maxn];

void uni(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (x > y) swap(x, y);
        fa[y] = x;
        siz[x] += siz[y];
    }
}


void solve() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        e[i].clear();
        siz[i] = 1;
        fa[i] = i;
        vis[i] = 0;
        c[i] = 0;
    }


    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }
    if (ll(1) * k * (k - 1) / 2 > m) {
        cout << -1 << endl;
        return;
    }
    queue<int> q;
    while (!q.empty()) q.pop();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = e[i].size();
        if (!vis[i] && c[i] < k - 1) {
            q.push(i);
            vis[i] = 1;
            cnt++;
        }
    }

    while (q.size()) {
        int now = q.front();
        q.pop();
        for (auto i : e[now]) {
            c[i]--;
            c[now]--;
            e[i].erase(now);
            if (c[i] < k - 1 && !vis[i]) {
                q.push(i);
                vis[i] = 1;
                cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && c[i] == k - 1) {
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int flag = 1;
        for (auto i : e[now]) {
            for (auto j : e[now]) {
                if (i == j) continue;
                if (e[i].find(j) == e[i].end()) {
                    flag = 0;
                    break;
                }
                if (!flag) break;
            }
        }
        if (flag && c[now] == k - 1) {
            cout << 2 << endl << now << " ";
            for (auto i : e[now]) {
                cout << i << " ";
            }
            cout << endl;
            return;
        } else {
            for (auto i : e[now]) {
                c[i]--;
                c[now]--;
                e[i].erase(now);
                if (!vis[i] && c[i] == k - 1) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] < k && !vis[i]) {
            vis[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto i : e[now]) {
            e[i].erase(now);
            c[i]--;
            c[now]--;
            if (c[i] < k && !vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
        }
    }
    if (cnt) {
        cout << 1 << " " << cnt << endl;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    } else
        cout << -1 << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
