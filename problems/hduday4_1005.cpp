/**
  * @Problem hduday4_1005.cpp
  * @Time 2020/7/30 13:11
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

const int maxn = 1e5 + 5;

ll dp[10005];
int A[maxn];


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        A[1] = 1;
        string now;
        cin >> now;
        for (int i = 2; i <= n; i++) {
            string s;
            cin >> s;
            if (s == now) {
                A[i] = 0;
            } else {
                A[i] = 1;
            }
            now = s;
        }

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!A[i]) {
                dp[i] = dp[i - 1];
                dp[i] %= mod;
            } else {
                dp[i] = dp[i - 2] + dp[i - 1];
                dp[i] %= mod;
            }
        }
        cout << dp[n] << endl;
    }


    return 0;
}
