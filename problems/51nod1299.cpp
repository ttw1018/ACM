/**
  * @Problem 51nod1299.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/11 18:30
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

struct edge {
    int from, to;

    edge(int a = 0, int b = 0) : from(a), to(b) {}
} e[maxn * 2];

int head[maxn], tot;

void add_edge(int x, int y) {
    e[++tot] = edge(head[x], y);
    head[x] = tot;
    e[++tot] = edge(head[y], x);
    head[y] = tot;
}

int ans;
int pos[maxn];
int flag[maxn];

void dfs(int x, int fa) {
    int sta[3];
    memset(sta, 0, sizeof(sta));
    for (int i = head[x]; i; i = e[i].from) {
        int to = e[i].to;
        if (to != fa) {
            dfs(to, x);
            sta[flag[to]]++;
        }
    }
    if (pos[x]) {
        ans += sta[1];
        flag[x] = 2;
    } else if (sta[2] && sta[1]) {
        flag[x] = 0;
        ans++;
    } else if (sta[1]) {
        flag[x] = 1;
    } else if (sta[2]) {
        flag[x] = 2;
    } else if (sta[0]) {
        flag[x] = 0;
    }
}

int dep[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        dep[x]++;
        dep[y]++;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        pos[x] = 1;
        if (dep[x] == 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        flag[i] = 1;
    }

    for (int i = 0; i <= n; i++) {
        if (dep[i] == 1) {
            dfs(i, i);
            if (flag[i] == 2) {
                ans++;
            }
            break;
        }
    }
    cout << ans << endl;


    return 0;
}
