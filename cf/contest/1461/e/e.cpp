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
  ll k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  if (x > y) {
    ll cnt;
    if (k + y <= r) {
      cnt = (k - l) / (x - y);
    } else {
      cnt = (k - l) / x + (k - (k - l) / x * x + (k - l) / x * y) / x;
    }
    if (cnt >= t) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  ll now = k;
  ll ans = 0;
  bool flag = 1;

  if (now + y <= r)
    now += y;

  for (ll i = 0; i < x;) {
    ll add = (now - l) / x;
    if (y - add <= ans)
      break;
    ans += add;
    now -= add * x;
    ll cc = min(add, (r - now) / y);
    if (cc == 0) {
      flag = 0;
      break;
    }
    now += cc * y;
    i += cc;
  }

  if (flag || ans >= t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
