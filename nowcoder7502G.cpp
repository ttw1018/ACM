//
// Created by ttw on 2020/10/31.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int mod = 400009;
const int mod1 = 156007;
const int mod2 = 399983;
const int maxn = 100005;

ll a[maxn];


ll qp (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

ll c1[maxn], inv1, c2[maxn], inv2;
void init() {
    c1[0] = 1;
    for (int i = 1; i < maxn; i++) {
        c1[i] = c1[i - 1] * mod1 % mod;
    }
    inv1 = qp(mod1, mod - 2);
    c2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        c2[i] = c2[i - 1] * mod2 % mod;
    }
    inv2 = qp(mod2, mod - 2);
}

map<ll, int> vis1, vis2;


int main () {
    int n;
    init();
    while (~scanf("%d", &n)) {
        vis1.clear();
        vis2.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        ll now1 = 0, now2 = 0;
        for (int i = 1; i <= n; i++) {
            now1 = (now1 + a[i] * c1[i] % mod) % mod;
            now2 = (now2 + a[i] * c2[i] % mod) % mod;
        }
        vis1[now1] = 1;
        vis2[now2] = 1;
        int cnt = 1;

        for (int i = 1; i <= n; i++) {
            now1 -= a[i] * c1[1] % mod;
            now1 = (now1 % mod + mod) % mod;
            now1 = now1 * inv1 % mod;
            now1 = (now1 + a[i] * c1[n] % mod) % mod;

            now2 -= a[i] * c2[1] % mod;
            now2 = (now2 % mod + mod) % mod;
            now2 = now2 * inv2 % mod;
            now2 = (now2 + a[i] * c2[n] % mod) % mod;

            if (!vis1[now1] || !vis2[now2]) {
                cnt++;
                vis1[now1] = 1;
                vis2[now2] = 1;
            }
        }
        reverse(a + 1, a + 1 + n);
        now1 = 0, now2 = 0;
        for (int i = 1; i <= n; i++) {
            now1 = (now1 + a[i] * c1[i] % mod) % mod;
            now2 = (now2 + a[i] * c2[i] % mod) % mod;
        }
        if (!vis1[now1] || !vis2[now2]) {
            cnt++;
            vis1[now1] = 1;
            vis2[now2] = 1;
        }

        for (int i = 1; i <= n; i++) {
            now1 -= a[i] * c1[1] % mod;
            now1 = (now1 % mod + mod) % mod;
            now1 = now1 * inv1 % mod;
            now1 = (now1 + a[i] * c1[n] % mod) % mod;

            now2 -= a[i] * c2[1] % mod;
            now2 = (now2 % mod + mod) % mod;
            now2 = now2 * inv2 % mod;
            now2 = (now2 + a[i] * c2[n] % mod) % mod;

            if (!vis1[now1] || !vis2[now2]) {
                cnt++;
                vis1[now1] = 1;
                vis2[now2] = 1;
            }
        }




        cout << cnt << endl;
    }


    return 0;
}
