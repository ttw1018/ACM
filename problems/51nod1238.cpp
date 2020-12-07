/**  * @Problem 51nod1238.cpp
  * @Time 2020/8/7 15:14
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e6 + 6;
ll s[maxn];
ll inv6;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


int prime[maxn], tot, phi[maxn];
bool vis[maxn];


void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}

void init() {
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && prime[j] * i < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }

    for (int i = 1; i < maxn; i++) {
        s[i] = s[i - 1] + ll(1) * phi[i] * i % mod * i % mod;
        MOD(s[i]);
    }
    inv6 = qp(6, mod - 2);
}

ll get1(ll x) {
    x %= mod;
    return (x * (x + 1) / 2) % mod;
}

ll get(ll x) {
    x = get1(x);
//    cout << x << endl;
    return x * x % mod;
}

ll get(ll l, ll r) {
    l--;
    l %= mod;
    r %= mod;

    l = (2 * l + 1) % mod * l % mod * (l + 1) % mod * inv6 % mod;
    r = (2 * r + 1) % mod * r % mod * (r + 1) % mod * inv6 % mod;

    ll ans = r - l;
    MOD(ans);
    return ans;
}

unordered_map<ll, ll> w;

ll djs(ll x) {
    if (x < maxn) return s[x];
    if (w[x]) return w[x];
    ll ans = get(x);
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ans -= get(l, r) * djs(x / l) % mod;
        MOD(ans);
    }
    return w[x] = ans;
}


int main() {
    init();
    ll n;
    cin >> n;
    ll ans = 0;
//    //869356306
//    110592617
//    cout << s[1000005] << endl << endl;
//    ll a = 5000000;


//    cout << djs(maxn) << endl;


    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (djs(r) - djs(l - 1)) * get1(n / l) % mod;
        MOD(ans);
    }
    cout << ans << endl;

    return 0;
}
