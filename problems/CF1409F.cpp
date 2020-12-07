/**
  * @Problem CF1409F.cpp
  * @Time 2020/9/18 22:46
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn];

ll dp[205][205][205];

int main() {
    int n, k;
    cin >> n >> k;
    cin >> (s + 1);
    char c1, c2;
    cin >> c1 >> c2;
    ll ans = 0;
    if (c1 == c2) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == c1) cnt++;
        }
        cnt = min(cnt + k, n);
        ans = ll(cnt) * (cnt - 1) / 2;
        cout << ans << endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            for (int c = 0; c <= i; c++) {
                if (dp[i - 1][j][c] >= 0)
                    dp[i][j][c] = dp[i - 1][j][c];
                if (s[i] == c1) {
                    if (c - 1 >= 0 && dp[i - 1][j][c - 1] >= 0)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c - 1]);
                } else {
                    if (j - 1 >= 0 && c - 1 >= 0 && dp[i - 1][j - 1][c - 1] >= 0)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - 1][c - 1]);
                }

                if (s[i] == c2) {
                    if (dp[i - 1][j][c] >= 0)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c] + c);
                } else {
                    if (j - 1 >= 0 && dp[i - 1][j - 1][c] >= 0)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - 1][c] + c);
                }
                if (i == n) {
                    ans = max(ans, dp[i][j][c]);
                }
            }
        }
    }

    cout << ans << endl;


    return 0;
}
