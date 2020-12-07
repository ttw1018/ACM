/**
  * @Problem nowcoder5672H.cpp
  * @Time 2020/8/1 12:31
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


int main() {
    ll n, k;
    for (ll N = 1; N < 100; N++) {
        for (k = 1; k < 100; k++) {
            n = N;
            ll ans = (n + k - 1) % mod;
            for (ll l = 2, r; l <= k; l = r + 1) {
                if (l > n) {
                    break;
                }
                r = n / (n / l);
                r = min(r, k);
                ans += (r - l + 1) % mod * ((n / l) % mod) % mod;
                ans %= mod;
            }
//    cout << ans << endl;
            n--;
//    cout << ans << endl;
            for (ll l = 2, r; l <= k; l = r + 1) {
                if (l > n) {
                    break;
                }
                r = n / (n / l);
                r = min(r, k);
                ans += (r - l + 1) % mod * ((n / l) % mod) % mod;
                ans %= mod;
            }
            cout << N << " " << k << " " << (ans % mod + mod) % mod << endl;

        }
    }
//    cin >> n >> k;
//    ll ans = n % mod;
//    for (ll l = 2, r; l <= k; l = r + 1) {
//        if (l > n) {
//            break;
//        }
//        r = n / (n / l);
//        r = min(r, k);
//        ans += (r - l + 1) % mod * ((n / l) % mod) % mod;
//        ans %= mod;
//    }
////    cout << ans << endl;
//    n--;
////    cout << ans << endl;
//    for (ll l = 2, r; l <= k; l = r + 1) {
//        if (l > n) {
//            ans += k - l + 1;
//            ans %= mod;
//            break;
//        }
//        r = min(r, k);
//        r = n / (n / l);
//        ans += (r - l + 1) % mod * ((n / l + 1) % mod) % mod;
//        ans %= mod;
//    }
//    cout << (ans % mod + mod) % mod << endl;
//
//
    return 0;
}
