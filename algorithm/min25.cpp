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

const int N = 1000010;

#define LL __int128

namespace Min25 {

    int prime[N], id1[N], id2[N], flag[N], ncnt, m;

    LL g[N], sum[N], a[N], T, n;

    inline int ID(LL x) {
        return x <= T ? id1[x] : id2[n / x];
    }

    inline LL calc(LL x) {
        return x * (x + 1) / 2 - 1;
    }

    inline LL f(LL x) {
        return x;
    }

    inline void init() {
        T = sqrt(n + 0.5);
        for (int i = 2; i <= T; i++) {
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (LL l = 1; l <= n; l = n / (n / l) + 1) {
            a[++m] = n / l;
            if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt; i++) 
            for (int j = 1; j <= m && (LL)prime[i] * prime[i] <= a[j]; j++) 
                g[j] = g[j] - (LL)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
    }

    inline LL solve(LL x) {
        if (x <= 1) return x;
        return n = x, init(), g[ID(n)];
    }

}

LL getsum (LL x) {
    return x * (x + 1) / 2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, k;
        scanf("%lld%lld", &n, &k);
        LL ans = getsum(n) - 3 + Min25::solve(n) - 2;
        ans = ans % k;
        ll res = res;
        printf("%lld\n", res);
        
    }

}
