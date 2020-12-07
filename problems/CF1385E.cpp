/**
  * @Problem CF1385E.cpp
  * @Time 2020/7/21 8:55
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;
vector<int> v[maxn];
int deg[maxn];

map<int, int> w[maxn];


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            w[i].clear();
            deg[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 1) {
                v[x].push_back(y);
                deg[y]++;
            } else {
                w[x][y] = w[y][x] = 1;
            }
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto i : v[now]) {
                if (--deg[i] == 0) {
                    q.push(i);
                    cnt++;
                }
            }
            for (auto i : w[now]) {
                int to = i.first;
                v[now].push_back(to);
                w[to].erase(now);
            }
        }
        if (cnt != n) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (auto j : v[i]) {
                printf("%d %d\n", i, j);
            }
        }
    }


    return 0;
}


