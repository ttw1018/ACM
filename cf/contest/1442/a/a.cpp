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

const int maxn = 1e5 + 5;

int a[maxn];
int l[maxn], r[maxn], dp[maxn];

int main()
{
    int T;
    cin >> T;
a:
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dp[1] = a[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1], a[i]);
            // if (dp[i] < a[i] - (a[i - 1] - dp[i - 1])) {
            //     cout << "NO" << endl;
            //     goto a;
            // }
            dp[i] = min(dp[i], a[i] - (a[i - 1] - dp[i - 1]));
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        if (dp[n] >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}