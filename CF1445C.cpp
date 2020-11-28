//
// Created by ttw on 2020/11/1.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int prime[maxn], tot;
bool vis[maxn];
void init () {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)  break;
        }
    }
}


int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        ll p, q;
        cin >> p >> q;
        if (p % q != 0) {
            cout << p << endl;
            continue;
        }
        ll ans = 1;
        for (int i = 0; i < tot && prime[i] <= q; i++) {
            if (q % prime[i] == 0) {
                ll tmp = p;
                ll now1 = 1, now2 = 1;
                while (tmp % prime[i] == 0) tmp /= prime[i], now1 *= prime[i];
                while (q % prime[i] == 0) q /= prime[i], now2 *= prime[i];
                ans = max(ans, tmp * now2 / prime[i]);
            }
        }
        if (q > 1) {
            ll tmp = p;
            ll now1 = 1, now2 = 1;
            while (tmp % q == 0) tmp /= q, now1 *= p;
            ans = max(ans, tmp);
        }
        cout << ans << endl;


    }



    return 0;
}
