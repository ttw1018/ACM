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

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
      cout << "a";
    for (int i = 1; i <= n - k; i++)
      cout << char('a' + i % 3);
    cout << endl;
  }
  return 0;
}
