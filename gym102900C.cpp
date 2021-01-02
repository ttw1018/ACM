//
// Created by ttw on 2020/12/19.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;


int a[35], b[35];
ll val[35][2][2];
ll dp[35][2][2];
ll ans = 0;

ll dfs (int now, int limit1, int limit2, int yes) {

    if (!yes && val[now][limit1][limit2] != -1) {
        ans += val[now][limit1][limit2];
        ans %= mod;
    }
    if (dp[now][limit1][limit2] != -1) {
        return dp[now][limit1][limit2];
    }

    int m1 = limit1 ? a[now] : 1;
    int m2 = limit2 ? b[now] : 1;
    if (now == 0) {
        int cnt;
        if (m1 == 1 && m2 == 1) cnt = 3;
        else cnt = (m1 + 1) * (m2 + 1);
        if (!yes) {
            ans += cnt;
            ans %= mod;
        }
        return cnt;
    }

    ll cnt = 0;
    ll v = 0;
    for (int i = 0; i <= m1; i++) {
        for (int j = 0; j <= m2; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            if ((i ^ j) == 1) {
                if (!yes) {
                    ll k = dfs(now - 1, (limit1 && i == m1), (limit2 && j == m2), 1);
                    v += (now + 1) * k % mod;
                    v %= mod;
                    cnt += k;
                    cnt %= mod;
                }
                else {
                    cnt += dfs(now - 1, (limit1 && i == m1), (limit2 && j == m2), 1);
                    cnt %= mod;
                }
            }
            else {
                cnt += dfs(now - 1, (limit1 && i == m1), (limit2 && j == m2), yes);
                cnt %= mod;
            }
        }
    }

    if (!yes) {
        v %= mod;
        val[now][limit1][limit2] = v;

    }
    cnt %= mod;
    dp[now][limit1][limit2] = cnt;
    ans += v;
    ans %= mod;
    return cnt;
}



void solve (ll x, ll y) {
    int c1 = 0, c2 = 0;

    while (x) {
        if (x & 1) {
            a[c1] = 1;
        }
        else {
            a[c1] = 0;
        }
        c1++;
        x >>= 1;
    }
    while (y) {
        if (y & 1) {
            b[c2] = 1;
        }
        else {
            b[c2] = 0;
        }
        c2++;
        y >>= 1;
    }

    int cnt = max(c1, c2) - 1;
    memset(dp, -1, sizeof(dp));
    memset(val, -1, sizeof(val));
    for (int i = c1; i <= cnt; i++) {
        a[i] = 0;
    }
    for (int i = c2; i <= cnt; i++) {
        b[i] = 0;
    }
    ans = 0;
    dfs(cnt, 1, 1, 0);
    cout << ans - 1 << "\n";
}



int main () {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
//    T = 100000;
    while (T--) {
        ll x, y;
        cin >> x >> y;
//        x = rand() % 100000000;
//        y = rand() % 100000000;
        if (x == 0 && y == 0) {
            cout << 0 << endl;
            continue;
        }
        solve(x, y);
    }
    return 0;
}


