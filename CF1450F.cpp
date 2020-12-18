//
// Created by ttw on 2020/12/8.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int a[maxn];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1, 0);
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] > (n + 1) / 2) {
                flag = 0;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        vector<int> v(n + 1, 0);
        v[a[1]]++;
        v[a[n]]++;
        int ma = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                ans++;
                v[a[i]] += 2;
                ma = max(ma, v[a[i]]);
            }
        }


        cout << ans + max(0, ma - (ans + 2)) << endl;

    }
    return 0;
}
