/**
  * @Problem CF1393D.cpp
  * @Time 2020/8/7 22:30
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2005;
char s[maxn][maxn];

ll cnt[maxn][maxn];
//int c1[maxn][maxn], c2[maxn][maxn], now[maxn][maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }

    ll ans = n * m;

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            char c = s[i][j];
            if (c != s[i + 1][j] || c != s[i - 1][j] || c != s[i][j + 1] || c != s[i][j - 1]) cnt[i][j] = 0;
            else cnt[i][j] = 1 + min(min(cnt[i - 1][j - 1], cnt[i - 1][j + 1]), cnt[i - 2][j]);
            ans += cnt[i][j];

        }
    }
    cout << ans << endl;
    return 0;
}
