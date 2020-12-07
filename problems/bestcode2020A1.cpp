/**
  * @Problem bestcode2020A1.cpp
  * @Time 2020/7/19 14:01
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2e4 + 200;
int dp[maxn];
int x[115], y[115];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, ((m - 1) / x[i] + 1) * y[i]);
        }
        cout << ans << endl;
    }


    return 0;
}
