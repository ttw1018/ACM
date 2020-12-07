/**
  * @problem cf1382d.cpp
  * @time 2020/7/22 0:22
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

const int maxn = 4e3 + 5;
int a[maxn];

int ma[maxn], dp[maxn];
int pos[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int now = 0;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
            if (a[i] > now) {
                now = a[i];
            }
            ma[i] = now;
            pos[a[i]] = i;
        }
        int p = 2 * n;
        vector<int> v;
        while (p > 0) {
            int len = p - pos[ma[p]] + 1;
            v.push_back(len);
            p = pos[ma[p]] - 1;
        }

        for (int i = 1; i <= 2 * n; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;

        for (auto i : v) {
//            cout << i << endl;
            vector<int> vv;
            for (int j = i; j <= 2 * n; j++) {
                if (dp[j - i]) {
                    vv.push_back(j);
                }
            }
            for (auto j : vv) {
                dp[j] = 1;
            }
        }
        if (dp[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
