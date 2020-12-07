/**
  * @Problem CF1409E.cpp
  * @Time 2020/9/18 20:34
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int a[maxn];
int x[maxn], y[maxn];

int dp[maxn];

struct node {
    int l, r, v;
} t[maxn * 4];

void build(int k, int l, int r) {
    t[k].l = l;
    t[k].r = r;
    t[k].v = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    t[k].v = 0;
}

void upd(int k, int p, int v) {
    if (t[k].l == t[k].r) {
        t[k].v = v;
        return;
    }
    int m = (t[k].l + t[k].r) >> 1;
    if (p <= m) upd(k << 1, p, v);
    else upd(k << 1 | 1, p, v);
    t[k].v = max(t[k << 1].v, t[k << 1 | 1].v);
}

int que(int k, int l, int r) {
    if (t[k].l >= l && t[k].r <= r) {
        return t[k].v;
    }
    int m = (t[k].l + t[k].r) >> 1;
    if (r <= m) {
        return que(k << 1, l, r);
    } else if (l > m) {
        return que(k << 1 | 1, l, r);
    } else {
        return max(que(k << 1, l, r), que(k << 1 | 1, l, r));
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> y[i];
        }
        if (n <= 2) {
            cout << n << endl;
            continue;
        }

        sort(x + 1, x + 1 + n);

        build(1, 1, n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i > 1 && x[i] == x[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                int p = upper_bound(x + 1, x + 1 + n, x[i] + k) - x;
                p = min(p, n + 1);
                dp[i] = p - i;
            }
//            cout << dp[i] << " ";
            upd(1, i, dp[i]);
        }
//        cout << endl;


        for (int i = 1; i <= n; i++) {
            int p = upper_bound(x + 1, x + 1 + n, x[i] + k) - x;
            if (p <= n) {
                ans = max(ans, dp[i] + que(1, p, n));
            } else {
                ans = max(ans, dp[i]);
            }
        }


        cout << ans << endl;


    }


    return 0;
}
