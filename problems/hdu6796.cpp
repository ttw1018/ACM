/**
  * @Problem hdu6796.cpp
  * @Time 2020/7/30 20:52
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

int num[20];

ll c[20][20];

void init() {
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i < 20; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int d;

map<vector<int>, ll> dp[20][2];

vector<int> sta(10, 0);

int check(vector<int> sta) {
    for (int i = 0; i <= 9; i++) {
        if (i != d && sta[i] >= sta[d]) {
            return 0;
        }
    }
    return 1;
}

ll dfs(int len, int zero, int limit, vector<int> sta) {
    if (len == 0) {
        return dp[len][zero][sta] = check(sta);
    }
    if (!limit && dp[len][zero].find(sta) != dp[len][zero].end()) {
        return dp[len][zero][sta];
    }


    if (!zero && !limit) {
        ll res = 0;
        for (int i = 0; i <= len; i++) {
            int flag = 0;
            for (int j = 0; j < 10; j++) {
                if (j != d && sta[j] >= sta[d] + i) {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            ll dp0[20];
            memset(dp0, 0, sizeof(dp0));
            dp0[len - i] = c[len][i];
            for (int j = 0; j < 10; j++) {
                if (j == d) continue;
                for (int cc = 1; cc <= len - i; cc++) {
                    for (int c1 = 1; c1 <= cc && c1 + sta[j] < sta[d] + i; c1++) {
                        dp0[cc - c1] += c[cc][c1] * dp0[cc];
                    }
                }
            }
            res += dp0[0];
        }
//        cout << len << endl;
//        for (int i = 0; i < 10; i++) {
//            cout << sta[i] << " ";
//        }
//        cout << endl;
        return dp[len][zero][sta] = res;
    }

    int ma = limit ? num[len] : 9;
    ll res = 0;
    for (int i = 0; i <= ma; i++) {
        if (zero && i == 0) {
            res += dfs(len - 1, 1, 0, sta);
        } else {
            if (i == d || sta[i] + 1 < sta[d] + len - 1) {
                sta[i]++;
                res += dfs(len - 1, 0, limit && i == num[len], sta);
                sta[i]--;
            }
        }
    }
    if (!limit) {
        return dp[len][zero][sta] = res;
    }
    return res;
}


ll solve(ll x) {
    int all = 0;
    while (x) {
        num[++all] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) sta[i] = 0;
    return dfs(all, 1, 1, sta);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j].clear();
            }
        }
        ll l, r;
        cin >> l >> r >> d;
        cout << solve(r) - solve(l - 1) << endl;
    }

    return 0;
}
