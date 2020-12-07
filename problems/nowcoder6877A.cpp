/**
  * @Problem nowcoder6877A.cpp
  * @Time 2020/8/4 8:53
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

const int maxn = 305;
ll A[maxn][maxn], dp[maxn][maxn], tmp[maxn][maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
        sort(A[i] + 1, A[i] + m + 1);
        ll sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += A[i][j];
            tmp[i][j] = sum + j * j;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= m; i++) dp[1][i] = tmp[1][i];
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 0; k <= m && j - k >= i - 1; k++) {
                dp[i][j] = min(dp[i - 1][j - k] + tmp[i][k], dp[i][j]);
            }
        }
    }
    cout << dp[n][n] << endl;


    return 0;
}
