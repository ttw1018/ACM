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

//const int mod = 1e9 + 7;
const int maxn = 5e5 + 5;
const int mod = 998244353;

int n;
bool vis[maxn];
int cnt[100][100];
void dfs (int x, int len) {
    if (len == n) {
//        for (int i = 1; i <= 2 * n; i++) {
//            if (vis[i])
//                cout << i << " ";
//        }
//        cout << endl;
//        for (int i = 2 * n; i >= 1; i--) {
//            if (!vis[i]) {
//                cout << i << " ";
//            }
//        }
        int i = 1, j = 2 * n;
        for ( ;i <= 2 * n && j >= 1; ) {
            if (vis[i] && !vis[j]) {
                cnt[i][j]++;
                i++;
                j--;
            }
            else if (vis[i]) {
                j--;
            }
            else i++;
        }
        return;
    }
    if (x > n * 2) return;
    dfs(x + 1, len);
    vis[x] = 1;
    dfs(x + 1, len + 1);
    vis[x] = 0;
}

ll a[maxn];
ll c[maxn], inv[maxn];

void init () {
    c[0] = 1;
    inv[1] = 1;
    c[1] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        c[i] = c[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    for (int i = 2; i <= n; i++) {
        inv[i] = inv[i - 1] * inv[i] % mod;
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + 2 * n);

    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += a[i];
        sum1 %= mod;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        sum2 += a[i];
        sum2 %= mod;
    }

    ll ans = (sum2 - sum1 + mod) % mod;

    init();
    cout << ans * c[2 * n] % mod * inv[n] % mod * inv[n] % mod << endl;

    return 0;
}
