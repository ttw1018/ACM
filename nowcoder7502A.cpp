#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

ll dp[maxn][3];
char s[maxn];


int main() {
    int n;
    while (cin >> n) {
        cin >> (s + 1);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][2];
            dp[i][1] = dp[i - 1][1];
            if (s[i] == '2') {
                dp[i][0]++;
                dp[i][2] += dp[i][1];
            } else if (s[i] == '0') {
                dp[i][1] += dp[i][0];
                ans += dp[i][2];
            }
        }
        cout << dp[n][1] << endl;
        cout << ans << endl;
    }


    return 0;
}