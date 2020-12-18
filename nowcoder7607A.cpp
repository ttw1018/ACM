#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long ll;

const int maxn = 1e7 + 5;
bool vis[maxn];

int prime[maxn];

int tot;
ll sum[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            for (ll j = 1; j < maxn; j *= i) {
                sum[j] = i;
            }
        }
    }

    for (int i = 1; i < maxn; i++) {
        if (sum[i]) sum[i] += sum[i - 1];
        else sum[i] = sum[i - 1] + 1;
    }
}


int main() {
    init();
    int l, r;
    scanf("%d%d", &l, &r);

    printf("%lld\n", sum[r] - sum[l - 1]);
}