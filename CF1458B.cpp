/*
*   FileName: CF1458B
*   Author: ttw
*   Time: 5:45 下午:2020/12/19
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

using namespace std;

const int maxn = 1e4;

ll dp[105][10010];
ll cap[105];
ll val[105];
ll n;
ll sum;
ll ans[105];

ll getans(ll c, ll v)
{
    return min(c * 2, (sum - v) + 2 * v);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cap[i];
        cin >> val[i];
        sum += val[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            for (int k = maxn; k >= 0; k--)
            {
                if (k - cap[i] < 0 || dp[j - 1][k - cap[i]] == -1)
                    continue;
                if (dp[j - 1][k - cap[i]] == -1)
                    continue;
                dp[j][k] = max(dp[j][k], dp[j - 1][k - cap[i]] + val[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= maxn; k++)
        {
            if (dp[i][k] != -1)
                ans[i] = max(ans[i], getans(k, dp[i][k]));
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i] % 2 == 0)
            printf("%d.0000000000 ", ans[i] / 2);
        else
            printf("%d.5000000000 ", ans[i] / 2);
    }
    printf("\n");
    return 0;
}