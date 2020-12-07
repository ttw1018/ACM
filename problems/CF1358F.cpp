/**
  * @Problem CF1358F.cpp
  * @Time 2020/7/20 19:29
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, k;

const int maxn = 2e5 + 5;

int in[maxn];

map<int, int> v[maxn];
int cnt[maxn];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);


        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v[x][y] = 1;
            v[y][x] = 1;
        }

        if (k == 1) {
            printf("%d\n", n - 1);
            continue;
        }

        queue<int> q;


        while (!q.empty()) q.pop();

        for (int i = 1; i <= n; i++) {
            if (v[i].size() == 1) {
                q.push(i);
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            int fa;
            if (v[now].size() == 1) {
                for (auto i : v[now]) fa = i.first;
            } else {
                continue;
            }

            cnt[fa]++;
            v[fa].erase(now);
            if (cnt[fa] >= k) {
                cnt[fa] %= k;
                ans++;
            }
            if (v[fa].size() == 1 && cnt[fa] == 0) {
                q.push(fa);
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
