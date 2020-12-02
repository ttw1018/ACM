#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

ll t[maxn * 4], a[maxn];
ll lz[maxn * 4];

void prop(int k, int l, int r) {
    if (lz[k]) {
        t[k] = ll(1) * (r - l + 1) * lz[k];
        a[l] = a[r] = lz[k];
        if (l < r) {
            lz[2 * k] = lz[2 * k + 1] = lz[k];
        }
        lz[k] = 0;
    }

}

void build(int k, int l, int r) {
    if (l == r) {
        t[k] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
    t[k] = t[k * 2] + t[k * 2 + 1];
}

void upd(int k, int L, int R, int i, int y) {
    prop(k, L, R);
    if (L > i || a[R] >= y) return;
    if (a[L] <= y && R <= i) {
        lz[k] = y;
        prop(k, L, R);
        return;
    }
    int m = (L + R) / 2;
    upd(k * 2, L, m, i, y);
    upd(k * 2 + 1, m + 1, R, i, y);
    t[k] = t[k * 2] + t[k * 2 + 1];
}

ll query(int k, int L, int R, int i, ll &y) {
    prop(k, L, R);
    if (R < i) return 0;
    if (L >= i && y >= t[k]) {
        y -= t[k];
        return R - L + 1;
    }
    if (L == R) return 0;
    if (a[R] > y) return 0;
    int m = (L + R) / 2;
    int ans = query(k * 2, L, m, i, y);
    ans += query(k * 2 + 1, m + 1, R, i, y);
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int ope;
        cin >> ope;
        if (ope == 1) {
            ll x, y;
            cin >> x >> y;
            upd(1, 1, n, x, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}

