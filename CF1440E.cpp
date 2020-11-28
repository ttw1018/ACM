//
// Created by ttw on 2020/11/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

struct node {
    int l, r;
    ll f, sum;
} t[maxn * 4];

void build(int k, int l, int r) {
    t[k].l = l;
    t[k].r = r;
    if (l == r) {
        cin >> t[k].sum;
        return;
    }
    int m = (l + r) / 2;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
    t[k].sum = t[k * 2].sum + t[k * 2 + 1].sum;
}

void down(int k) {
    t[k * 2].f = t[k * 2 + 1].f = t[k].f;
    t[k * 2].sum = (t[k * 2].r - t[k * 2].l + 1) * t[k].f;
    t[k * 2 + 1].sum = (t[k * 2 + 1].r - t[k * 2 + 1].l + 1) * t[k].f;
    t[k].f = 0;
}

void upd(int k, int l, int r, ll v) {
    if (t[k].l >= l && t[k].r <= r) {
        t[k].f = v;
        t[k].sum = (t[k].r - t[k].l + 1) * v;
        return;
    }
    if (t[k].f) down(k);
    int m = (t[k].l + t[k].r) >> 1;
    if (l <= m) upd(k * 2, l, r, v);
    if (r > m) upd(k * 2 + 1, l, r, v);
    t[k].sum = t[k * 2].sum + t[k * 2 + 1].sum;
}

ll que(int k, int x) {
    if (t[k].l == t[k].r) {
        return t[k].sum;
    }
    if (t[k].f) {
        down(k);
    }
    int m = (t[k].l + t[k].r) / 2;
    ll ans = 0;
    if (x <= m) ans = que(k * 2, x);
    if (x > m) ans = que(k * 2 + 1, x);
    t[k].sum = t[k * 2].sum + t[k * 2 + 1].sum;
    return ans;
}

ll que(int k, int l, int r) {
    if (t[k].l >= l && t[k].r <= r) {
        return t[k].sum;
    }
    if (t[k].f) down(k);
    int m = (t[k].l + t[k].r) / 2;
    ll ans = 0;
    if (l <= m) ans += que(k * 2, l, r);
    if (r > m) ans += que(k * 2 + 1, l, r);
    t[k].sum = t[k * 2].sum + t[k * 2 + 1].sum;
    return ans;
}

int main () {
    int n, q;
    cin >> n >> q;

    build(1, 1, n);

    while (q--) {
        int ope;
        cin >> ope;
        if (ope == 1) {
            ll x, y;
            cin >> x >> y;
            if (que(1, x) >= y) continue;
            int l = 1, r = x;
            while(l < r) {
                int m = (l + r) / 2;
                int now = que(1, m);
                if (now >= y) l = m + 1;
                else r = m;
            }
            upd(1, l, x, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            int l = x, r = n;

            while (l < r) {
                int m = (l + r) / 2;
                ll now = que(1, m, n);
                if (now > y) l = m + 1;
                else r = m;
            }
            cout << n - l + 1 << endl;

        }
    }

    return 0;
}

