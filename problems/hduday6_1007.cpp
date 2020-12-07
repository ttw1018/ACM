/**
  * @Problem hduday6_1007.cpp
  * @Time 2020/8/6 14:38
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

const int maxn = 2e5 + 5;
const int N = 2e5;

ll a[maxn], b[maxn];

void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}

int vis[maxn];
ll pre[maxn], pre2[maxn];
ll res[maxn];

void init(ll k, ll x) {

    for (int i = 1; i <= N; i++) {
        a[i] = qp(i, k);
        pre[i] = a[i] + pre[i - 1];
        MOD(pre[i]);
    }

    for (int i = 2; i * i <= N; i++) {
        for (int j = i * i; j <= N; j += i * i) {
            vis[j] = 1;
        }
    }


    for (int i = N; i > 1; i--) {
        ll now = 0;
        for (int j = i; j <= N; j += i) {
            now += a[j];
            MOD(now);
            b[i] -= b[j];
            MOD(b[i]);
        }
        b[i] += qp(now, x);
        MOD(b[i]);
    }

    for (int i = 2; i <= N; i++) {
        pre2[i] = pre2[i - 1] + b[i];
        MOD(pre2[i]);
    }


    for (int i = 2; i <= N; i++) {
        if (!vis[i]) {
            res[i] = res[i - 1] + b[i] * i;
            MOD(res[i]);
        }
    }

}

void solve(int n, int x) {
    ll all = qp(pre[n], x) - pre2[n];
    MOD(all);
    ll ans = all + res[n];
    MOD(ans);
    cout << ans << endl;
}

int main() {
    ll t, k, x, n;
    scanf("%d%d%d", &t, &k, &x);
    init(k, x);
    while (t--) {
        scanf("%d", &n);
        solve(n, x);
    }
    return 0;
}
