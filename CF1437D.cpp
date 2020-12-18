#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

int a[maxn];

int dp[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> v;
        int cnt = 1;
        for (int i = 3; i <= n; i++) {
            if (a[i] > a[i - 1]) cnt++;
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        int all = v.size();
        int pre = v[0];
        int ans = 1;
        for (int i = 1; i < all;) {
            int cnt = 0;
            for (int j = 0; j < pre && i < all; i++, j++) {
                cnt += v[i];
            }
            pre = cnt;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}