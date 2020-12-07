/**
  * @Problem CF1440B.cpp
  * @Time 2020/11/17 22:43
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
ll a[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n * k; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        int p = n * k + 1;
        while (k--) {
            p -= n / 2 + 1;
            ans += a[p];
        }
        cout << ans << endl;
    }


    return 0;
}
