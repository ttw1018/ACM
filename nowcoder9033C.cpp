//
// Created by ttw on 2020/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;

const int mod = 20000311;

int a[maxn];
int vis[maxn];

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= n) {
            vis[a[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            len = i;
            break;
        }
    }

    int p = 0;
    ll ans = 0;
    ll now = 1;
    for (int i = 1; i <= len; i++) {
        while(p < n && a[p] < i) {
            p++;
        }

        ans += qp(2, n - p - vis[i]) * now * i;
        ans %= mod;
        now = now * (qp(2, vis[i]) - 1 + mod) % mod;
    }
    cout << ans << endl;


    return 0;
}