#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

// const int mod = 1e9 + 7;
// const int mod = 998244353;

const int maxn = 1e5 + 5;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    char c[505][505];

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> c[i][j];
      }
    }

    int cnt[505][505];
    memset(cnt, 0, sizeof(cnt));
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        if (c[i][j] == '*') {
          cnt[i][j] = 1;
          cnt[i][j] +=
              min(cnt[i + 1][j], min(cnt[i + 1][j - 1], cnt[i + 1][j + 1]));
        }
      }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans += cnt[i][j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
