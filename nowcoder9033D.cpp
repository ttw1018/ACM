//
// Created by ttw on 2020/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 5;
int a[maxn];

struct question {
    int id, l, r;
} q[maxn];

ll ans[maxn];

struct node {
    int l, r;
    ll v, f;
} t[maxn * 4];

vector<int> v[maxn];

void build(int k, int l, int r) {
    t[k].l = l;
    t[k].r = r;
    if (l == r) return;
    int m = (l + r) / 2;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
}

void down(int k) {
    t[k * 2].f += t[k].f;
    t[k * 2 + 1].f += t[k].f;
    t[k * 2].v += (t[k * 2].r - t[k * 2].l + 1) * t[k].f;
    t[k * 2 + 1].v += (t[k * 2 + 1].r - t[k * 2 + 1].l + 1) * t[k].f;
    t[k].f = 0;
}

void upd(int k, int l, int r, ll v) {
    if (t[k].l >= l && t[k].r <= r) {
        t[k].f += v;
        t[k].v += (t[k].r - t[k].l + 1) * v;
        return;
    }
    if (t[k].f)
        down(k);
    int m = (t[k].l + t[k].r) / 2;
    if (l <= m) upd(k * 2, l, r, v);
    if (r > m) upd(k * 2 + 1, l, r, v);
    t[k].v = t[k * 2].v + t[k * 2 + 1].v;
}

ll que(int k, int l, int r) {
    if (t[k].l >= l && t[k].r <= r) {
        return t[k].v;
    }
    if (t[k].f) down(k);
    ll ans = 0;
    int m = (t[k].l + t[k].r) / 2;
    if (l <= m) ans += que(k * 2, l, r);
    if (r > m) ans += que(k * 2 + 1, l, r);
    t[k].v = t[k * 2].v + t[k * 2 + 1].v;
    return ans;
}

vector<question> qq[maxn];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].id = i;
        qq[r].push_back(q[i]);
    }
    build(1, 1, n);

    for (int i = 1, l = 1, r = 0; i <= n; i++) {
        v[a[i]].push_back(i);
        if (v[a[i]].size() >= k) {
            r = max(r, v[a[i]][v[a[i]].size() - k]);
        }
        if (v[a[i]].size() > k) {
            l = max(l, v[a[i]][v[a[i]].size() - k - 1] + 1);
        }
//        cout << l << " " << r << endl;
        if (l <= r) {
            upd(1, l, r, 1);
        }
        for (auto qe : qq[i]) {
            ans[qe.id] = que(1, qe.l, qe.r);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}