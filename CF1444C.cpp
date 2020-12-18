#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 1e6 + 5;
typedef long long ll;

int a[N], fa[N], pre[N * 10], tot;
int vis[N];

int find(int x) {
    if (x == fa[x]) {
        return x;
    } else {
        int now = find(fa[x]);
        pre[++tot] = x;
        fa[x] = now;
        return fa[x];

    }
}

void add(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        if (fx > fy)
            swap(fx, fy);
        fa[fy] = fx;
        pre[++tot] = fy;
    }
}

map<pair<int, int>, vector<pair<int, int>>> mp;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= 2 * n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int xx = a[x], yy = a[y];
        if (xx > yy)
            swap(xx, yy);
        if (xx == yy) {
            add(x + n, y);
            add(y + n, x);
            if (find(x) == find(y) && !vis[xx]) {
                k--;
                vis[xx] = 1;

            }
        } else {
            mp[{xx, yy}].push_back({x, y});
        }
    }
    ll ans = ll(k) * (k - 1) / 2;
    for (auto i : mp) {
        if (vis[i.first.first] || vis[i.first.second]) {
            continue;
        }
        // cout << i.first.first << " " << i.first.second << endl;
        int cnt = tot;
        for (auto j : i.second) {
            int x = j.first;
            int y = j.second;
            add(x, y + n);
            add(y, x + n);
            if (find(x) == find(y)) {
                ans--;
                break;
            }
        }
        while (tot > cnt) {
            fa[pre[tot]] = pre[tot];
            tot--;
        }
    }
    cout << ans << endl;
}