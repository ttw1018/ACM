#include <cstdlib>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

const int maxn = 2e3 + 5;
// const int mod = 1e9 + 7;


struct node {
    int l, r;
    double center;
    bool operator < (const node a) const {
        return l + r < a.l + a.r;
    }
} a[maxn];

int c[maxn];

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + 1 + m);
    for (int i = 1; i + k - 1 <= n; i++) {
        int now = 0;
        for (int j = m; j >= 1; j--) {
            now += max(0, min(a[j].r, i + k - 1) - max(a[j].l, i) + 1);
            c[j] = max(c[j], now);
        }
        // for (int j = m; j >= 1; j--) {
        //     cout << c[j] << " ";
        // }
        // cout << endl;
    }


    int ans = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        int now = 0;
        for (int j = 1; j <= m; j++) {
            now += max(0, min(a[j].r, i + k - 1) - max(a[j].l, i) + 1);
            ans = max(ans, c[j + 1] + now);
        }
    }
    cout << ans << endl;
    return 0;

}

