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

int a[505];

// int main()
// {
//     int T;
//     cin >> T;
//     a:
//     while (T--) {
//         int n, x;
//         cin >> n >> x;
//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//         }
//         int ans = 0;
//         if (is_sorted(a + 1, a + 1 + n)) {
//             cout << ans << endl;
//             goto a;
//         }

//         for (int i = 1; i <= n; i++) {
//             if (a[i] > x) {
//                 swap(a[i], x);
//                 ans++;
//             }
//             if (i > 1 && a[i] < a[i - 1]) break;
//             if (is_sorted(a + 1, a + 1 + n)) {
//                 cout << ans << endl;
//                 goto a;
//             }

//         }
//         cout << -1 << endl;
//     }

//     return 0;
// }

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (is_sorted(a.begin(), a.end())) {
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> dp(n, vector<int>(501, 1e9));

        for (int i = 0; i < n; i++) {
            if (a[i] > x && (i == 0 || a[i - 1] <= x)) {
                dp[i][x] = 1;
            }
            if (i < n - 1 && a[i] > a[i + 1]) {
                break;
            }
        }

        int ans = int(1e9);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 500; j++) {
                if (dp[i][j] == 1e9)
                    continue;
                if (i == n || (j <= a[i + 1]) && is_sorted(a.begin() + i + 1, a.end())) {
                    ans = min(ans, dp[i][j]);
                }
                
                bool good = true;

                for (int k = i + 1; k < n; k++) {
                    int pr = k == i + 1 ? j : a[k - 1];
                    if (good && a[i] >= pr && a[i] < a[k]) {
                        dp[k][a[i]] = min(dp[k][a[i]], dp[i][j] + 1);
                    }
                    good &= a[k] >= pr;
                }
            }
        }
        if (ans == 1e9) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}