/**
  * @Problem 51nod1296.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/11 14:25
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 5e3 + 5;


int p[maxn];
ll dp[2][maxn];
ll sum[2][maxn];


void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}

// 1 a[n] > a[n - 1]
// 2 a[n] < a[n - 1]
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= a; i++) {
        int x;
        cin >> x;
        x++;
        p[x] = 2;
        p[x + 1] = 1;
    }
    for (int i = 1; i <= b; i++) {
        int x;
        cin >> x;
        x++;
        p[x] = 1;
        p[x + 1] = 2;
    }
    sum[1][1] = 1;
//    for (int i = 2; i <= n; i++) {
//        cout << p[i] << " ";
//    }
//    cout << endl;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (p[i] == 0) {
                dp[i & 1][j] = sum[(i & 1) ^ 1][i - 1];
            } else if (p[i] == 1) {
                dp[i & 1][j] = sum[(i & 1) ^ 1][j - 1];
            } else {
                dp[i & 1][j] = sum[(i & 1) ^ 1][i - 1] - sum[(i & 1) ^ 1][j - 1];
            }
            MOD(dp[i & 1][j]);
            sum[i & 1][j] = sum[i & 1][j - 1] + dp[i & 1][j];
            MOD(sum[i & 1][j]);
        }
//        cout << sum[i & 1][i] << endl;
    }

    cout << sum[n & 1][n] << endl;


    return 0;
}
