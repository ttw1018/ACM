//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll n, k, d, a, y;

ll get(ll a, ll b) {
    ll ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (b & (1 << i)) {
            if (a >= (1 << i))  {
                a -= (1 << i);
                ans += 1 << i;
            }
        }
    }
    return ans;
}

int main () {
    cin >> n >> a >> d >> k >> y;
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ll z = y - (a * i + i * (i - 1) * d / 2);
        if (z < 0) continue;
        z /= n - i;
        ll x = get(z, k);
        ans = min(ans, ((x ^ k) + k - x)  * (n - i));
    }
    cout << ans << endl;
    
    return 0;
}