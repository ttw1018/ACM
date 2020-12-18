//
// Created by ttw on 2020/12/13.
//

#pragma GCC optimize(3,"Ofast","inline")
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

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;

const int maxn = 4e4 + 5;
bool vis[maxn];
int prime[maxn], cnt;

void findprime() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int main () {
    findprime();
    int T;
    scanf("%d", &T);
    vector<ll> v[63];

    unordered_map<ll, int> w;

    for (int i = 0; i < cnt; i++) {
        ll now = prime[i];
        int cc = 1;
        while (now <= 1e18 / prime[i]) {
            v[cc++].push_back(now);
            now *= prime[i];
        }
    }

    while (T--) {
        ll x;
        scanf("%lld", &x);
        ll all = x;
        if (x == 1) {
            puts("0");
            continue;
        }
        if (w.find(x) != w.end()) {
            printf("%d\n", w[x]);
            continue;
        }
        int ans = 63;
        for (int i = 0; i < cnt; i++) {
            int pr = prime[i];
            if (x % pr == 0) {
                int cc = 0;
                while (x % pr == 0)  {
                    x /= pr;
                    cc++;
                }
                ans = min(ans, cc);
            }
        }
        if (x == 1 || ans == 1) {
            w[all] = ans;
            printf("%d\n", ans);
            continue;
        }
        ll now;
        now = pow(x, 1.0 / 3);
        if (now * now * now == x || (now + 1) * (now + 1) * (now + 1) == x) {
            ans = min(ans, 3);
            w[all] = ans;
            printf("%d\n", ans);
            continue;
        }

        now = pow(x, 0.5);
        if (now * now == x || (now + 1) * (now + 1) * (now + 1) == x) {
            ans = min(ans, 2);
            w[all] = ans;
            printf("%d\n", ans);
            continue;
        }
        puts("1");

    }

    return 0;
}
