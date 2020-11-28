#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[205];
int dp[205][405];

int main () {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = 0; i <= 2 * n; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2 * n; j++) {
                dp[i][j] = 1e9;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int t = i; t <= 2 * n; t++) {
                dp[i][t] = min(dp[i][t - 1], dp[i - 1][t - 1] + abs(t - a[i]));
            }
        }
        cout << dp[n][2 * n] << endl;
    }

    return 0;
}
