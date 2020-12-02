#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7
//const int mod = 998244353;

const int maxn = 1e5 + 5l;
bool vis[maxn];
ll k;
ll a[maxn];
ll sg[maxn];

// ll get(ll x)
// {
//     if (x == 1)
//         return 1;
//     if (x % k == 1) {
//         return get(x / k);
//     }

//     return x - (x - 1) / k - 1;
// }
//
ll get(long long x)
{
    while (x > k && !((x - 1) % k))
        x = (x - 1) / k;
    return x - 1 - (x - 1) / k;
}

ll v[maxn];

int main()
{
    int n;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i] = get(a[i]);
        ans ^= v[i];
    }

    // cout << ans << endl;
    cout << (ans ? "Alice" : "Bob") << " ";

    if (ans) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1)
                continue;
            ll now = ans ^ v[i];
            ll x = (now - 1) / (k - 1) * k + (now - 1) % (k - 1) + 2;

            if (now == 0)
                x = 1;

            ll res = x;

            ll l = (a[i] - 1) / k + 1;
            while (1) {
                if (res > a[i] || res < 0)
                    break;
                if (res >= l) {
                    cout << i << " " << res << endl;
                    exit(0);
                }
                res = res * k + 1;
            }
        }
    }

    return 0;
}