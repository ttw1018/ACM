/**
  * @Problem CF1400D.cpp
  * @Time 2020/8/25 23:49
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int mod = 1e9 + 7;

const int maxn = 3005;
int a[maxn];

int cnt[3005][3005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> v[3005];

        for (int i = 1; i <= n; i++) {
            v[a[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cnt[i][j] = cnt[i - 1][j];
            }
            cnt[i][a[i]]++;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int now = cnt[n][i];
            if (now >= 4) {
                ans += ll(1) * now * (now - 1) * (now - 2) * (now - 3) / 24;
            }

        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j]) continue;
                int pos = upper_bound(v[a[i]].begin(), v[a[i]].end(), j) - v[a[i]].begin();
//                cout << pos << endl;
                for (int k = pos; k < v[a[i]].size(); k++) {
                    ans += cnt[n][a[j]] - cnt[v[a[i]][k]][a[j]];
                }

            }
        }
        cout << ans << endl;


    }


    return 0;
}
