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

// const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 1e5 + 5;

const int mod = 1000000007;

ll sum[1005][1005];
ll dp[1005][1005];

class Solution {
public:
    /**
     * 
     * @param n int整型 乐谱总音符数
     * @param m int整型 重音符数
     * @param k int整型 重音符之间至少的间隔
     * @return long长整型
     */
    long long solve_bangbang(int n, int m, int k)
    {
        // write code here
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(dp));
        k++;
        for (int i = 1; i <= n; i++) {
            sum[i][1] = i;
            if (i <= k)
                continue;
            for (int j = 2; j <= m; j++) {
                dp[i][j] = sum[i - k][j - 1];
                sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
            }
        }

        return sum[n][m];
    }
};

int main()
{
    Solution test;
    cout << test.solve_bangbang(10, 2, 1);

    return 0;
}