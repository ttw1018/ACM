/**
  * @Problem hdu6804.cpp
  * @Time 2020/7/31 13:12
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(time(NULL));

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;
const int M = 1e6 + 5;

ll dp[M * 2 + 1];


int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(-x, y));
        }
//        random_shuffle(v.begin(), v.end());
        shuffle(v.begin(), v.end(), rnd);

        ll lim = 1000 * sqrt(n + m) * 4;

        for (int i = 0; i <= M * 2; i++) {
            dp[i] = -1;
        }

        dp[M] = 0;

        ll l = M, r = M;

        for (int i = 0; i < v.size(); i++) {
            ll now = v[i].first;
            ll val = v[i].second;
            l = min(l, l + now);
            r = max(r, r + now);
            l = max(l, M - lim);
            r = min(r, M + lim);
            if (now > 0) {
                for (int j = r; j >= l; j--) {
                    if (dp[j - now] != -1) {
                        dp[j] = max(dp[j], dp[j - now] + val);
                    }
                }
            } else {
                for (int j = l; j <= r; j++) {
                    if (dp[j - now] != -1) {
                        dp[j] = max(dp[j], dp[j - now] + val);
                    }
                }
            }
        }
        cout << dp[M] << endl;


    }


    return 0;
}


