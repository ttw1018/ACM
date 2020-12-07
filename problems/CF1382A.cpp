/**
  * @Problem CF1382A.cpp
  * @Time 2020/7/21 22:37
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> w;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            w[a] = 1;
        }
        int flag = 0;
        int ans;
        for (int j = 1; j <= m; j++) {
            int b;
            cin >> b;
            if (!flag && w[b]) {
                flag = 1;
                ans = b;
            }
        }
        if (flag) {
            cout << "YES" << endl << 1 << " " << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
