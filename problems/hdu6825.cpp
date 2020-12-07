/**
  * @Problem hdu6825.cpp
  * @Time 2020/8/5 21:12
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

const int maxn = 4e6 + 5;


ll rev[maxn], a[maxn], rev2[maxn];

void init() {
    a[0] = 1;
    a[1] = 1;
    rev[1] = 1;
    rev[0] = 1;
    for (int i = 2; i < maxn; i++) {
        a[i] = i * a[i - 1] % mod;
        rev[i] = (mod - mod / i) * rev[mod % i] % mod;
    }

    for (int i = 2; i < maxn; i++) {
        rev[i] = rev[i] * rev[i - 1] % mod;
    }

    rev2[0] = 1;

    rev2[1] = 499122177;

    for (int i = 1; i < maxn / 2; i++) {
        rev2[i] = rev2[i - 1] * rev2[1] % mod;
    }
}

ll getc(int x, int y) {
    if (x == y || y == 0) return 1;
    return a[x] * rev[y] % mod * rev[x - y] % mod;
}

ll qp(ll a, ll b) {
    ll ans;
    for (ans = 1; b; a = a * a % mod, b >>= 1) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

ll ans[maxn];


int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << "0 ";
        }
        ll sum = 0;
        for (int i = n / 2 + 1; i <= n; i++) {
            int b = 2 * i - n - 1;
            ans[i] = getc(i - 1, n - i) * a[n - i] % mod * a[b] % mod * rev2[b / 2] % mod * rev[b / 2] % mod;
            sum = (sum + ans[i]) % mod;
//            cout << ans[i] << endl;
        }
        ll re = qp(sum, mod - 2);
        for (int i = n / 2 + 1; i <= n; i++) {
            cout << ans[i] * re % mod;
            if (i == n) cout << endl;
            else cout << " ";
        }

    }


    return 0;
}


