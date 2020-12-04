#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 5e3 + 5;

int dp[maxn][maxn];

char s1[maxn], s2[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    cin >> (s1 + 1) >> (s2 + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(0, dp[i][j - 1] - 1);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            if (s1[i] == s2[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}