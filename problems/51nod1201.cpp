/**
  * @Problem 51nod1201.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/11 11:01
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int dp[350][50001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i * (i + 1) / 2 <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - i] + dp[i - 1][j - i];
            dp[i][j] %= mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i * (i + 1) / 2 <= n; i++) {
        ans += dp[i][n];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
