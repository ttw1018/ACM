/**
  * @Problem hdu2020day1_1005.cpp
  * @Time 2020/7/21 12:59
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 9;

const ll gen = 383008016;

ll a = 691504013, b = 308495997;

ll qp(ll a, ll b) {
    ll ans = 1;
    b %= mod - 1;
    a %= mod;
    if (a == 1) return 0;
    if (a == 0) return 0;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

const int maxn = 1e5 + 5;
ll c[maxn], inv[maxn];

void init() {
    c[0] = 1;
    c[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < maxn; i++) {
        c[i] = i * c[i - 1] % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    for (ll i = 2; i < maxn; i++) {
        inv[i] = inv[i] * inv[i - 1] % mod;
    }
}

ll get(ll a, ll b) {
    if (a == 0) return 0;
    ll ans = c[a] * inv[b] % mod * inv[a - b] % mod;
    return ans;
}


ll sum(ll q, ll n) {
    if (q == 1) { return n % mod; }
    ll ans = (qp(q, n) - 1 + mod) % mod * qp(q - 1, mod - 2) % mod;
    return ans;
}

void solve(ll n, ll c, ll k) {

//    ll n, c, k;
//        scanf("%lld %lld %lld", &n, &c, &k);

    n++;
    n %= mod - 1;
    ll ans = 0;
    ll base1 = qp(a, c % (mod - 1));
    ll base2 = qp(qp(b, c % (mod - 1)), mod - 2);
    ll aa = 1, bb = qp(b, c % (mod - 1) * k % (mod - 1));
    for (int i = 0; i <= k; i++) {
        ll k1 = i, k2 = k - k1;

        ll q1 = qp(a, c * k1) * qp(b, c * k2) % mod;
        ll q = aa * bb % mod;

        aa = aa * base1 % mod;
        bb = bb * base2 % mod;


        if (k2 & 1) {
            ans -= sum(q, n) * get(k, i) % mod;
        } else {
            ans += sum(q, n) * get(k, i) % mod;
        }
        ans = (ans % mod + mod) % mod;
    }

    ans = ans * qp(gen, k * (mod - 2) % (mod - 1)) % mod;

    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans);
}


int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, c, k;
        scanf("%lld %lld %lld", &n, &c, &k);

        n++;
//        n %= mod - 1;
        ll ans = 0;
        ll base1 = qp(a, c);
        ll base2 = qp(qp(b, c), mod - 2);
        ll aa = 1, bb = qp(b, c % (mod - 1) * k % (mod - 1));
        for (ll i = 0; i <= k; i++) {
            ll k1 = i, k2 = k - i;

            ll q = aa * bb % mod;
            aa = aa * base1 % mod;
            bb = bb * base2 % mod;

            if (k2 & 1) {
                ans -= sum(q, n) * get(k, i) % mod;
            } else {
                ans += sum(q, n) * get(k, i) % mod;
            }
            ans = (ans % mod + mod) % mod;
        }

        ans = ans * qp(gen, k * (mod - 2) % (mod - 1)) % mod;

        ans = (ans % mod + mod) % mod;
        printf("%lld\n", ans);

    }
    return 0;
}
