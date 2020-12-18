//
// Created by ttw on 2020/11/15.
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

using namespace std;

const int maxn = 2e5 + 5;

struct Line {
    int l, r, h, v;

    Line(int a = 0, int b = 0, int c = 0, int d = 0) : l(a), r(b), h(c), v(d) {}

    bool operator<(const Line now) const {
        if (h == now.h) {
            return l < now.l;
        }
        return h < now.h;
    }
} line[maxn];

vector<int> v;

int x[maxn];

struct node {
    int l, r, cnt, val, num;
    int lflag, rflag;
} t[maxn * 4];

void build(int k, int l, int r) {
    t[k].l = x[l], t[k].r = x[r];
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    build(k * 2, l, m);
    build(k * 2 + 1, m, r);
}

void push(int k) {
    if (t[k].cnt) {
        t[k].val = t[k].r - t[k].l;
        t[k].lflag = t[k].rflag = 1;
        t[k].num = 2;
    } else {
        t[k].val = t[k * 2].val + t[k * 2 + 1].val;
        t[k].lflag = t[k * 2].lflag;
        t[k].rflag = t[k * 2 + 1].rflag;
        t[k].num = t[k * 2].num + t[k * 2 + 1].num;
        if (t[k * 2].rflag == 1 && t[k * 2 + 1].lflag == 1) {
            t[k].num -= 2;
        }
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        line[i] = Line(a, c, b, 1);
        line[i + n] = Line(a, c, d, -1);
        v.push_back(a);
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++) {
        x[i + 1] = v[i];
    }
    int len = v.size();
    build(1, 1, len);

    sort(line + 1, line + 1 + 2 * n);
    ll ans = 0;
    ll pre = 0;
    line[2 * n + 1].h = line[2 * n].h;
    for (int i = 1; i <= 2 * n; i++) {
        upd(1, line[i].l, line[i].r, line[i].v);
        ans += abs(t[1].val - pre);
        pre = t[1].val;

        ans += t[1].num * (line[i + 1].h - line[i].h);
//        cout << t[1].val << " " << t[1].num << endl;
//        cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}