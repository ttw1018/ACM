#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll a[maxn], b[maxn];

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    int n;
    ll x;
    while (~scanf("%d%lld", &n, &x)) {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        ll sum = x;
        for (int i = 1; i <= n; i++) {
            sum = (sum + a[i] * b[i] % mod) % mod;
        }

        printf("%lld\n", sum * qp(x, n - 1) % mod);


    }

    return 0;
}
