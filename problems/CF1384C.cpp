/**
  * @Problem CF1384C.cpp
  * @Time 2020/7/24 22:30
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
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                flag = 1;
            }
        }
        if (flag) {
            cout << -1 << endl;
            continue;
        }
        int dp[25][25];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            dp[a[i] - 'a'][b[i] - 'a'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < 25; i++) {
            for (int j = 24; j > i; j--) {
                if (dp[i][j]) {
                    for (int k = i + 1; k < j; k++) {
                        if (dp[i][k] && dp[k][j]) {
                            dp[i][j] = 0;
                            break;
                        }
                    }
                }
            }

            for (int j = i + 1; j < 20; j++) {
                if (dp[i][j]) {
                    for (int k = j + 1; k < 20; k++) {
                        if (dp[i][k]) {
                            dp[i][k] = 0;
                            dp[j][k] = 1;
                        }
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < 24; i++) {
            for (int j = i + 1; j < 24; j++) {
                ans += dp[i][j];
            }
        }

        cout << ans << endl;


    }


    return 0;
}
