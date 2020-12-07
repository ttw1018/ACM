/**
  * @Problem bestcodefu1001.cpp
  * @Time 2020/8/9 19:03
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}

int main() {
    int T;
    cin >> T;
    ll inv = qp(100, mod - 2);
    while (T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        a = a * inv % mod;
        b = b * inv % mod;
        ll m = n * qp(a, mod - 2) % mod;
        ll ans = n;
        MOD(ans);
        ans -= (m - 1) * b % mod;
        MOD(ans);
        cout << ans << endl;


    }


    return 0;
}
