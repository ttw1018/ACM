#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 1e6 + 5;

ll dp[maxn];
ll ans = 0;

ll dfs(int x)
{
    if (x == 0) {
        return 1;
    }
    if (dp[x]) return dp[x];
    ll ans = 0;
    if (x & 1) {
        for (int i = 1; i <= x; i += 2) {
            ans += dfs((x - i) / 2);
            ans %= mod;
        }
    }
    else {
        for (int i = 0; i <= x; i += 2) {
            ans += dfs((x - i) / 2);
            ans %= mod;
        }
    }
    return dp[x] = ans;
}

int main()
{
    int n;
    cin >> n;
    cout << dfs(n);

    return 0;
}