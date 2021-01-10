#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// const int mod = 1e9 + 7;
// const int mod = 998244353
const int maxn = 1e5 + 5;

int cnt[maxn];

int val[maxn];

int ans[maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  for (int i = 1; i <= 100000; i++) {
    if (cnt[i]) {
      for (int k = 1; k * k <= i; k++) {
        if (i % k == 0) {
          val[k] += cnt[i];
          if (i / k != k) {
            val[i / k] += cnt[i];
          }
        }
      }
    }
  }
  for (int i = 1; i <= 100000; i++) {
    ans[val[i]] = max(ans[val[i]], i);
  }

  for (int i = 2; i <= 100000; i++) {
    for (int j = i * 2; j <= 100000; j++) {
      ans[i] = max(ans[i], ans[j]);
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
