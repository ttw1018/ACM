/**
  * @Problem hduday3_1005.cpp
  * @Time 2020/7/28 13:27
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
int A[maxn][2];
int val[maxn];
int fa[maxn];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

ll ans;

int cnt0, cnt1;

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx > fy) swap(fx, fy);
    if (fx != fy) {
        fa[fy] = fx;
        A[fx][0] += A[fy][0];
        A[fy][1] += A[fy][1];

        int vx = val[x], vy = val[y];
        if (vx > vy) swap(vx, vy);
        if (vy == 1) {
            printf("%d\n", ans);
            return;
        }

        if (vx == 1) {
            ans -= cnt1 - A[fx][1];
        }

        if (vx == 2) {
            ans -= cnt0 - A[fx][0];
        }
    }

    printf("%d\n", ans);

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            val[i] = x;
            if (x == 1) {
                cnt0++;
            } else {
                cnt1++;
            }
            A[i][0] = A[i][1] = 0;
            A[i][--x] = 1;
            fa[i] = i;
        }

        ans = 0;

        if (cnt1 >= 3) {
            ans += cnt1 * (cnt1 - 1) * (cnt1 - 2) / 6;
        }
        if (cnt1 >= 2) {
            ans += cnt1 * (cnt1 - 1) * cnt0 / 2;
        }
        printf("%d\n", ans);

        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            unite(x, y);
        }

    }


    return 0;
}
