/**
  * @Problem nowcoder5669H.cpp
  * @Time 2020/7/20 12:53
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;


struct Edge {
    int from, to;

    Edge() {};

    Edge(int a, int b) : from(a), to(b) {}
} e[maxn * 20];


int head[maxn], tot;

void add(int x, int y) {
    e[++tot] = Edge(head[x], y);
    head[x] = tot;
    e[++tot] = Edge(head[y], x);
    head[y] = tot;
}

void init() {
    for (int i = 2; i < maxn; i++) {
        for (int j = 2; i * j < maxn; j++) {
            add(i, i * j);
        }
    }
}

int vis[maxn];

bool dfs(int x, int ma) {
    for (int i = head[x]; i; i = e[i].from) {
        int to = e[i].to;
        if (to > ma) break;
        if (!vis[to] || dfs(vis[to], ma)) {
            vis[x] = to;
            vis[to] = x;
            return true;
        }
    }
    return false;
}


int main() {
    init();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                if (dfs(i, n)) cnt++;
            }
        }
        cout << cnt << endl;

    }


    return 0;
}
