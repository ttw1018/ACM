/**
  * @Problem hduday5_1001.cpp
  * @Time 2020/8/4 12:41
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;
const int inf = 0x7fffffff;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int maxn = 6e6 + 5;

ll inv[maxn];
ll a[maxn], b[maxn];

void init() {
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    ll now = 0;
    for (int i = 1; i < maxn; i++) {
        now += inv[i];
        now %= mod;
        a[i] = now;
    }

    now = 0;
    for (int i = 1; i < maxn; i++) {
        now += inv[i] * inv[i];
        now %= mod;
        b[i] = now;
    }

}

int main() {
    init();
    int T;
    cin >> T;
    ll inv2 = qp(2, mod - 2);
    while (T--) {
        ll n;
        cin >> n;
        ll ans = a[n];
        ll base = (n + 1) * inv2 % mod;

        ans = ans + 2 * base * b[n];

        cout << ans % mod << endl;

    }

    return 0;
}
