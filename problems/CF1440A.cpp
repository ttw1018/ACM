/**
  * @Problem CF1440A.cpp
  * @Time 2020/11/17 22:37
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int cnt0 = 0;
        for (auto i : s) {
            if (i == '0') cnt0++;
        }
        int ans = 1e9;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, i * c0 + (n - i) * c1 + h * abs(cnt0 - i));
        }
        cout << ans << endl;
    }


    return 0;
}
