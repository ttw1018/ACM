/**
  * @Problem nowcoder7329E.cpp
  * @Time 2020/9/15 19:35
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int a[maxn], p[maxn];

int n;

int st[maxn];

int l[maxn], r[maxn];

int s[maxn];

struct line {
    int l, r, v;
};

stack<line> ss;

int t[maxn];

int lowbit(int x) {
    return x & (-x);
}

void upd(int x, int v) {
//    cout << x << " " << v << endl;
    while (x <= n) {
        t[x] += v;
        x += lowbit(x);
    }
}

int que(int x) {
    int ans = 0;
    while (x) {
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) t[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[a[i]] = i;
        }
        int now = 0;
        for (int i = 1; i <= n; i++) {
            while (now && a[st[now]] < a[i]) now--;
            l[i] = now ? st[now] + 1 : 1;
            st[++now] = i;
        }
        now = 0;
        for (int i = n; i >= 1; i--) {
            while (now && a[st[now]] < a[i]) now--;
            r[i] = now ? st[now] - 1 : n;
            st[++now] = i;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ss.size() && ss.top().v > a[i]) {
                line pp;
                pp.v = a[i];
                pp.l = i;
                pp.r = i;
                while (ss.size() && ss.top().v > a[i]) {
                    line now = ss.top();
                    ss.pop();
                    if (now.l <= now.v && now.r >= now.v) {
                        upd(now.v, -1);
                    }
                    pp.l = now.l;
                }
                ss.push(pp);
                if (pp.l <= a[i] && pp.r >= a[i]) {
                    upd(a[i], 1);
                }
            } else {
                line now;
                now.v = a[i];
                now.l = now.r = i;
                ss.push(now);
                if (now.l <= a[i] && now.r >= a[i]) {
                    upd(a[i], 1);
                }
            }
            if (i == 5) {
            }

            if (p[i] <= i && r[p[i]] >= i) {
//            cout << i << endl;
                int f1 = l[p[i]];
                int f2 = p[i];
                ans += que(f2) - que(f1 - 1);
//                cout << f1 << " " << f2 << endl;
            }
//            cout << ans << endl;
        }
        cout << ans << endl;
        while (!ss.empty()) {
//            line now = ss.top();
            ss.pop();
//            cout << now.l << " " << now.r << " " << now.v << endl;
        }
//        break;
    }


    return 0;
}
