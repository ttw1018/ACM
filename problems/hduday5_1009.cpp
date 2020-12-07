/**
  * @Problem hduday5_1009.cpp
  * @Time 2020/8/4 12:33
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;
const int inf = 0x7fffffff;


ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}


int main() {
    int T;
    cin >> T;
    ll rev = qp(2, mod - 2) * 3 % mod;
    while (T--) {
        ll n;
        cin >> n;
        ll ans = qp(2, n) + 1;
        ans += 2 * qp(rev, n) % mod;
        ans = (ans % mod + mod) % mod;
        cout << ans << endl;

    }


    return 0;
}
