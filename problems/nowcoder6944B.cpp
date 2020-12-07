/**
  * @Problem nowcoder6944B.cpp
  * @Time 2020/8/22 9:51
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

int a[maxn];

ll ans[maxn];

vector<int> v[maxn];

void init() {
    for (int i = 1; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            v[j].push_back(i);
        }
    }
    for (int i = 1; i < maxn; i++) {
        reverse(v[i].begin(), v[i].end());
    }
}

struct edge {
    int from, to;

    explicit edge(int a = 0, int b = 0) : from(a), to(b) {}
} e[maxn * 2];

int head[maxn], tot;

void add(int x, int y) {
    e[++tot] = edge(head[x], y);
    head[x] = tot;
    e[++tot] = edge(head[y], x);
    head[y] = tot;
}

int son[maxn], siz[maxn];

void dfs(int now, int fa) {
    siz[now] = 1;
    int ma = 0;
    for (int i = head[now]; i; i = e[i].from) {
        int to = e[i].to;
        if (to != fa) {
            dfs(to, now);
            siz[now] += siz[to];
            if (siz[to] > ma) {
                ma = siz[to];
                son[now] = to;
            }
        }
    }
}

int ma[maxn];

map<int, int> cnt;

void insert(int now) {
    for (auto i : v[now]) {
        cnt[i]++;
    }
}

// now is the val of vertex
void query(int now, int rt) {
    for (auto i : v[now]) {
        if (i < ma[rt]) break;
        if (cnt[i]) {
            if (i == ma[rt]) {
                ans[rt] += cnt[i];
            } else if (i > ma[rt]) {
                ans[rt] = cnt[i];
                ma[rt] = i;
            }
            break;
        }
    }
}

void cal(int now, int fa, int rt) {
    query(a[now], rt);
    for (int i = head[now]; i; i = e[i].from) {
        int to = e[i].to;
        if (to == fa) continue;
        cal(to, now, rt);
    }
}

void ADD(int now, int fa) {
    insert(a[now]);
    for (int i = head[now]; i; i = e[i].from) {
        int to = e[i].to;
        if (to != fa) {
            ADD(to, now);
        }
    }
}


void dfs2(int now, int fa, int undo) {
    for (int i = head[now]; i; i = e[i].from) {
        int to = e[i].to;
        if (to != fa && to != son[now]) {
            dfs2(to, now, 1);
        }
    }
    if (son[now]) {
        dfs2(son[now], now, 0);
    }

    for (int i = head[now]; i; i = e[i].from) {
        int to = e[i].to;
        if (to != fa && to != son[now]) {
            cal(to, now, now);
            ADD(to, now);
        }
    }
    query(a[now], now);
    insert(a[now]);
    if (undo) {
        cnt.clear();
    }
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    dfs(1, 0);
    dfs2(1, 0, 1);

    for (int i = 1; i <= n; i++) {
        cout << ma[i] << " " << ans[i] << endl;
//        cout << son[i] << endl;
    }
    return 0;
}
