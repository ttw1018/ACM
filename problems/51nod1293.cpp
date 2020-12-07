/**
  * @Problem 51nod1293.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/11 11:49
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int A[1005][1005];

ll dp[1005][1005][2];

int main() {
    int n, m;
    ll k;
    cin >> m >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    dp[1][1][0] = k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i][j] == 0) {
                dp[i + 1][j][0] += dp[i][j][0];
                dp[i][j + 1][1] += dp[i][j][1];
            } else if (A[i][j] == 1) {
                ll all = dp[i][j][0] + dp[i][j][1];
                dp[i + 1][j][0] += all / 2;
                dp[i][j + 1][1] += all / 2;
                dp[i][j + 1][1] += all & 1;
            } else {
                ll all = dp[i][j][0] + dp[i][j][1];
                dp[i + 1][j][0] += all / 2;
                dp[i][j + 1][1] += all / 2;
                dp[i + 1][j][0] += all & 1;

            }
        }
    }
    cout << dp[n + 1][m][0] << endl;


    return 0;
}
