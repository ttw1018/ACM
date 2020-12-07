/**
  * @Problem hduday6_1001.cpp
  * @Time 2020/8/6 13:08
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

const int maxn = 1e6 + 5;
ll inv[maxn];

void init() {
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}

ll a[maxn];
ll sum[maxn];

void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}

ll now[maxn];

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = (sum[i - 1] + a[i]) % mod;

        ll cnt = n * (n + 1) / 2 % mod;
        MOD(cnt);

        cnt = qp(cnt, mod - 2);

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = i + 1 - 1;
            int r = n - i + 1;
            if (l <= r) {
                ll tmp = now[i - 1] + sum[r] - sum[l - 1];
                MOD(tmp);
                now[l] = now[r] = tmp;
            } else {
                break;
            }
        }


        for (int i = 1; i <= n; i++) {
            ans += now[i] * inv[i] % mod;
            MOD(ans);
        }

        ans = ans * cnt % mod;
        MOD(ans);
        printf("%lld\n", ans);

    }

    return 0;
}
