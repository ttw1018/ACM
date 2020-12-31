/* Generated by powerful Codeforces Tool
 * Author: Tiwent
 * Time: 2020-12-30 22:35:38
 **/

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

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

// const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 5;

ll a[maxn];

int cnt[70];
ll val[70];

int main() {
    int T;
    scanf("%d", &T);
    val[0] = 1;
    for (int i = 1; i <= 60; i++) {
        val[i] = val[i - 1] * 2 % mod;
    }
    while (T--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            ll now = a[i];
            for (int j = 0; j <= 60; j++) {
                if ((now >> j) & 1) cnt[j]++;
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll sum = 0;
            for (int j = 0; j <= 60; j++) {
                if ((a[i] >> j) & 1) {
                    sum = (sum + n * val[j] % mod) % mod;
                } else {
                    sum = (sum + cnt[j] * val[j] % mod) % mod;
                }
            }
            for (int j = 0; j <= 60; j++) {
                if ((a[i] >> j) & 1) {
                    ans = (ans + cnt[j] * sum % mod * val[j] % mod) % mod;
                }
            }
        }
        printf("%lld\n", ans);

    }


    return 0;
}