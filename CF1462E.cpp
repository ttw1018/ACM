/*
*   FileName: CF1462E
*   Author: ttw
*   Time: 4:37 下午:2020/12/19
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int a[maxn];

ll c[maxn], inv[maxn];

void init () {
    c[0] = c[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        c[i] = i * c[i - 1] % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    for (int i = 2; i < maxn; i++) {
        inv[i] = inv[i] * inv[i - 1] % mod;
    }
}

ll get (int n, int m) {
    return c[n] * inv[m] % mod * inv[n - m] % mod;
}

int main () {
    init();
//    for (int i = 1; i < 10; i++) {
//        for (int j = 0; j <= i; j++) {
//            cout << i << " " << j << " " << get(i, j) << endl;
//        }
//    }
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int ma = a[i] + k;
            int ed = upper_bound(a + 1, a + 1 + n, ma) - a - i - 1;
            if (ed >= m - 1) {
                ans += get(ed, m - 1);
                ans %= mod;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
