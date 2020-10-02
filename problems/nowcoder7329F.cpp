#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int maxn = 1e7 + 5;

int n, p, q;

ll f[maxn];

int prime[maxn];
bool vis[maxn];
int tot = 0;


ll qp (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


ll get (ll x) {
    if (p - q >= 0) {
        return (1 - qp(x, p - q) + mod) % mod;
    }
    else {
        ll now = qp(x, q - p);
        return (1 - qp(now, mod - 2) + mod) % mod; 
    }
}


ll g[maxn];

void init () {
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            f[i] = get(i);
            g[i] = qp(i, q);
            f[i] = f[i] * g[i] % mod;
        }
        for (int j = 0; j < tot && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) {
                f[i * prime[j]] = f[i] * f[prime[j]] % mod;
            }
            else {
                f[i * prime[j]] = f[i] * g[prime[j]];
                break;
            }
        }
    }
}

int main () {
    cin >> n >> p >> q;
    init();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << f[i] << " ";
        ans ^= f[i];
    }
    // cout << endl;
    cout << ans << endl;



    return 0;
}