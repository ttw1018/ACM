//
// Created by ttw on 2020/12/17.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

ll t[maxn], x[maxn];
bool vis[maxn];

struct node {
    ll t1, t2, x1, x2;
    node (ll a = 0, ll b = 0, ll c = 0, ll d = 0) : t1(a), t2(b), x1(c), x2(d) {}
};

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> t[i] >> x[i];
            vis[i] = 0;
        }

        ll now = 0;
        ll pos = 0;
        ll time = 0;
        ll pnow = 0;
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (t[i] >= time) {
                ll l = pnow;
                ll r = pos;
                if (l > r) swap(l, r);
                if (i > 1 && x[i - 1] >= l && x[i - 1] <= r) {
                    ans++;
//                    cout << i << endl;
                }
                now = t[i];
                time = t[i] + abs(x[i] - pos);
                pnow = pos;
                pos = x[i];
            }
            else {
                ll l = pnow, r;
                if (pos >= pnow) {
                    pnow += t[i] - t[i - 1];
                }
                else {
                    pnow -= t[i] - t[i - 1];

                }
                r = pnow;
                if (l > r) swap(l, r);
                if (i > 1 && l <= x[i - 1] && r >= x[i - 1]) {
                    ans++;
//                    cout << i << endl;
                }
            }
//            cout << t[i] << " " << pnow << " " << pos << endl;
        }
        if (pnow > pos)  swap(pos, pnow);

        if (x[n] >= pnow && x[n] <= pos) ans++;
        cout << ans << endl;

    }


    return 0;
}
