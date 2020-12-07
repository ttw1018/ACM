/**
  * @Problem nowcoder5669B.cpp
  * @Time 2020/7/20 12:08
*/



#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;


const int maxn = 1e6 + 5;
int tot;
int prime[maxn], vis[maxn], cnt[maxn];

void init() {
    cnt[1] = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            cnt[i] = 1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            cnt[i * prime[j]] = cnt[i] + cnt[prime[j]];
            if (i % prime[j] == 0) break;
        }
    }

}

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;

}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, c;
        scanf("%d %d", &n, &c);
        if (n == 1) {
            printf("1\n");
            continue;
        }
        ll ans = qp(c, cnt[n]);
        printf("%lld\n", ans);
    }


    return 0;
}
