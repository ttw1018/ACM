#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

struct node {
    int l, r;
    ll v, sum;
    node (int a = 0, int b = 0, int c = 0) : l(a), r(b), v(c) {}
} t[maxn * 4];

void push(int k) {
    t[k].sum = t[k * 2].sum + t[k * 2 + 1].sum;
    t[k].v = min(t[k * 2].v, t[k * 2 + 1].v);
}

void build (int k, int l, int r) {
    t[k] = node(l, r);
    if (l == r) {
        cin >> t[k].v;
        t[k].sum = t[k].v;
        return;
    }
    int m = (l + r) >> 1;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
    push(k);
}

void down(int k) {
    t[k * 2].v = max(t[k].v, t[k * 2].v);
    t[k * 2 + 1].v = max(t[k].v, t[k * 2 + 1].v);
    t[k * 2].sum = (t[k * 2].r - t[k * 2].l + 1) * t[k * 2].v;
    t[k * 2 + 1].sum = (t[k * 2 + 1].r - t[k * 2 + 1].l + 1) * t[k * 2 + 1].v;
}

void upd(int k, int l, int r, ll v) {
    if (t[k].l >= l && t[k].r <= r) {
        t[k].v = max(t[k].v, v);
        t[k].sum = max(t[k].sum, (t[k].r - t[k].l + 1) * t[k].v);
        return;
    }
    down(k);
    int m = (t[k].l + t[k].r) / 2;
    if (l <= m) upd(k * 2, l, r, v);
    if (r > m) upd(k * 2 + 1, l, r, v);
    push(k);
}

int que(int k, int l, int r) {
    if (t[k].l >= l && t[k].r <= r) {
        return t[k].sum;
    }
    down(k);
    ll ans = 0;
    int m = (t[k].l + t[k].r) >> 1;
    if (l <= m) ans += que(k * 2, l, r);
    if (r > m) ans += que(k * 2 + 1, l, r);
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
            ll r, x;
            cin >> r >> x;
            upd(1, 1, r, x);
        }
        else {
            ll x, y;
            cin >> x >> y;
            int l = x, r = n;
            while (l < r) {
                int m = (l + r) >> 1;
                ll sum = que(1, x, m);
                if (sum >= y) r = m;
                else l = m + 1;
            }
            cout << l - x + 1 << endl;
        }
    }
    return 0;
}
