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

int main() {
  string s;
  cin >> s;
  ll x, y;
  cin >> x >> y;

  int n = s.length();
  if (x < y) {
    swap(x, y);
    reverse(s.begin(), s.end());
  }

  for (int i = 0; i < n; i++) {

  }

  return 0;
}
