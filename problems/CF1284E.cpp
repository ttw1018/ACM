/**
  * @Problem CF1284E.cpp
  * @Time 2020/7/24 22:31
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int flag = 0;
        n = a.length();
        int dp[25][25];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            dp[a[i] - 'a'][b[i] - 'a'] = 1;
        }
        int ans = 0;

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                for (int k = 0; k < 20; k++) {
                    if (dp[i][j] && dp[i][k] && dp[k][j]) {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++)
                ans += dp[i][j];
        }


        cout << ans << endl;


    }


    return 0;
}
