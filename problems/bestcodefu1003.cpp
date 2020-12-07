/**
  * @Problem bestcodefu1003.cpp
  * @Time 2020/8/9 19:59
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

ll a[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        int l, k;
        scanf("%d%d%d", &n, &l, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        ll ma, mi;
        if (l + l - k >= n) {
            ma = ll(n - l + 1) * a[n - k + 1];
        } else {
            ma = ll(l - k + 1) * a[n - k + 1];
            for (int i = 1; i <= n - l + 1 - (l - k + 1); i++) {
                ma = ma + a[n - k + 1 - i];
            }
        }

        if (l + k - 1 >= n) {
            mi = ll(n - l + 1) * a[l - k + 1];
        } else {
            mi = ll(k) * a[l - k + 1];
            for (int i = 1; i <= n - l + 1 - k; i++) {
                mi = mi + a[l - k + 1 + i];
            }
        }
        cout << ma << " " << mi << endl;
    }

    return 0;
}
