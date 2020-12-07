/**
  * @Problem 51nod1237.cpp
  * @Time 2020/8/7 10:55
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

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
int phi[maxn], prime[maxn], tot;
bool vis[maxn];
ll s[maxn];
ll inv2;

void init() {
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j] % mod;
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1) % mod;
        }
    }
//    for (int i = 1; i < 10; i++) cout << phi[i] << " ";
//    cout << endl;
    for (int i = 1; i < maxn; i++) {
        s[i] = (s[i - 1] + phi[i]) % mod;
    }
}


unordered_map<ll, ll> w;

void MOD(ll &x) { x = (x % mod + mod) % mod; }

ll djs(ll x) {
    if (x < maxn) return s[x];
    if (w[x]) return w[x];
    ll ans = x % mod * ((x + 1) % mod) % mod * inv2 % mod;
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ans -= (r - l + 1) % mod * djs(x / l) % mod;
        MOD(ans);
    }
    return w[x] = ans;
}

ll get(ll l, ll r) {
    return djs(r) - djs(l - 1);
}


int main() {
    init();
    inv2 = qp(2, mod - 2);
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (n / l) % mod * ((n / l) % mod) % mod * get(l, r) % mod;
        MOD(ans);
    }
    cout << ans << endl;


    return 0;
}
