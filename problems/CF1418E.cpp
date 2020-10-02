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
const int maxn = 2e5 + 5;

ll a[maxn], sum[maxn];

ll qp (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % mod;
    }
    while (m--) {
        ll cnt, val;
        cin >> cnt >> val;
        int p = lower_bound(a + 1, a + 1 + n, val) - a - 1;
        ll x = p;
        ll y = n - p;

        if (y < cnt) {
            cout << 0 << endl;
        }
        else {
            ll sum1 = sum[x];
            ll sum2 = (sum[n] - sum[x] + mod) % mod;
            ll ans = (y - cnt) * qp(y, mod - 2) % mod * sum2 % mod + (y + 1 - cnt) * qp(y + 1, mod - 2) % mod * sum1 % mod;
            cout << ans % mod << endl;
        }
    }
    return 0;
}