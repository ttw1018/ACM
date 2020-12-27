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

char s[3][3];
void solve() {
  int sta;
  cin >> sta;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    cout << s[i] << endl;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
