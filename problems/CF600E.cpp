/**
  * @Problem CF600E.cpp
  * @Time 2020/8/23 14:56
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int val[maxn];
int n;

vector<int> e[maxn];

int siz[maxn], son[maxn];

void dfs(int now, int fa) {
    siz[now] = 1;
    int ma = 0;
    for (auto i : e[now]) {
        if (i != fa) {
            dfs(i, now);
            siz[now] += siz[i];
            if (siz[i] > ma) {
                ma = siz[i];
                son[now] = i;
            }
        }
    }
}

ll ans[maxn];

int cnt[maxn], ma;
ll sum;

int Son;

void add(int x, int fa, int v) {
    cnt[val[x]] += v;
    if (cnt[val[x]] > ma) {
        ma = cnt[val[x]];
        sum = val[x];
    } else if (cnt[val[x]] == ma) {
        sum += val[x];
    }

    for (auto i : e[x]) {
        if (i != fa && i != Son) {
            add(i, x, v);
        }
    }
}

void dfs2(int now, int fa, bool undo) {
    for (auto i : e[now]) {
        if (i != son[now] && i != fa)
            dfs2(i, now, 1);
    }
    if (son[now]) dfs2(son[now], now, 0), Son = son[now];

    add(now, fa, 1);
    Son = 0;
    ans[now] = sum;

    if (undo) add(now, fa, -1), sum = 0, ma = 0;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1, 0);

    dfs2(1, 0, 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}
