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

const int maxn = 1e5 + 5;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        a[i][j]--;
      }
    }
    pair<int, int> x(0, 1), y(0, 2), z(0, 3);

    string s;
    cin >> s;
    for (int i = 0; i < m; i++) {
      if (s[i] == 'L')
        y.first--;
      else if (s[i] == 'R')
        y.first++;
      else if (s[i] == 'U')
        x.first--;
      else if (s[i] == 'D')
        x.first++;
      else if (s[i] == 'I') {
        swap(y, z);
      } else {
        swap(x, z);
      }
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    // cout << x.first << " " << x.second << " " << y.first << " " << y.second
    // << " " << z.first << " " << z.second << endl;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int _x = i;
        int _y = j;
        int _z = a[i][j];
        int x_, y_, z_;
        if (x.second == 1) {
          x_ = _x + x.first;
        } else if (x.second == 2) {
          x_ = _y + x.first;
        } else if (x.second == 3) {
          x_ = _z + x.first;
        }
        if (y.second == 1) {
          y_ = _x + y.first;
        } else if (y.second == 2) {
          y_ = _y + y.first;
        } else {
          y_ = _z + y.first;
        }
        if (z.second == 1) {
          z_ = _x + z.first;
        } else if (z.second == 2) {
          z_ = _y + z.first;
        } else {
          z_ = _z + z.first;
        }
        x_ = (x_ % n + n) % n;
        y_ = (y_ % n + n) % n;
        z_ = (z_ % n + n) % n;
        ans[x_][y_] = z_;
      }
    }
    for (auto i : ans) {
      for (auto j : i) {
        cout << j + 1 << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
