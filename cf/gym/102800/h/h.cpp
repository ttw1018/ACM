#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int mu[maxn], prime[maxn];
bool vis[maxn];
int tot;
void init() {
  mu[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        break;
      } else {
        mu[i * prime[j]] = -mu[i];
      }
    }
  }
}

ll cnt[maxn];
ll ans[maxn];

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++)
    cnt[i] = ans[i] = 0;
  int a;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    for (int k = 1; k * k <= a; k++) {
      if (a % k == 0) {
        cnt[k]++;
        if (a / k != k) {
          cnt[a / k]++;
        }
      }
    }
  }
  for (int k = 1; k <= m; k++) {
    for (int d = 1; d <= m / k; d++) {
      ans[k] += ll(mu[d]) * cnt[d * k] * cnt[d * k];
    }
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a);
    printf("%lld\n", ans[a]);
  }
}

int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
