#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
const int mod = 998244353;

vector<int> e[maxn];

int dis[maxn][20];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
  }
  ll ans = 0;
  memset(dis, -1, 4);

  return 0;
}
