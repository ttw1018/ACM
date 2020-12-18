#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

struct rectangle {
    int l, r, h, v;

    rectangle(int a = 0, int b = 0, int c = 0, int d = 0) : l(a), r(b), h(c), v(d) {}

    bool operator<(const rectangle now) const {
        if (h == now.h) return l < now.l;
        return h < now.h;
    }
} a[maxn * 2];

struct node {
    int l, r;
    int v;
    int cnt;
} t[maxn * 8];

vector<int> v;
int x[maxn * 2];

void build(int k, int l, int r) {
    t[k].l = x[l];
    t[k].r = x[r];
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    build(k * 2, l, m);
    build(k * 2 + 1, m, r);
}

void push(int k) {
    if (t[k].cnt) {
        t[k].v = t[k].r - t[k].l;
    } else {
        t[k].v = t[k * 2].v + t[k * 2 + 1].v;
    }
}

void upd(int k, int l, int r, int v) {
    if (t[k].l >= l && t[k].r <= r) {
        t[k].cnt += v;
        push(k);
        return;
    }
    if (l < t[k * 2].r) upd(k * 2, l, r, v);
    if (r > t[k * 2 + 1].l) upd(k * 2 + 1, l, r, v);
    push(k);
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r, b, d;
        cin >> l >> b >> r >> d;
        a[i] = rectangle(l, r, b, 1);
        a[i + n] = rectangle(l, r, d, -1);
        v.push_back(l);
        v.push_back(r);
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++) {
        x[i + 1] = v[i];
    }

    int len = v.size();

    build(1, 1, len);

    sort(a + 1, a + 1 + 2 * n);

    int p = 1;
    ll ans = 0;

    for (int i = 1; i <= 2 * n; i++) {
        ans += ll(1) * t[1].v * (a[i].h - a[i - 1].h);
        upd(1, a[i].l, a[i].r, a[i].v);
    }
    cout << ans << endl;

}

