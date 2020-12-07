/**
  * @Problem CF1380E.cpp
  * @Time 2020/7/17 19:13
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;
int A[maxn * 2];

vector<int> v[maxn * 2];
int fa[maxn];

int f[maxn * 2][20];
int dep[maxn * 2];

void dfs(int x, int fath) {
    f[x][0] = fath;
    dep[x] = dep[fath] + 1;
    for (int i = 1; i < 19; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (auto to : v[x]) {
        dfs(to, x);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 18; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) {
            x = f[x][i];
        }
    }


    if (x == y) return x;
    for (int i = 18; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];

}

int cnt[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        fa[i] = i;
    }
    for (int i = 1; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[i + m].push_back(fa[x]);
        v[i + m].push_back(fa[y]);
        fa[x] = i + m;
    }
    int root = m + m - 1;
    dfs(root, root);

    for (int i = 1; i < n; i++) {
        int lc = lca(A[i], A[i + 1]);
        if (lc > m) {
            cnt[lc - m]++;
        } else {
            cnt[0]++;
        }
    }
    for (int i = 1; i < m; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < m; i++) {
        cout << n - 1 - cnt[i] << " ";
    }
    cout << endl;


    return 0;
}
