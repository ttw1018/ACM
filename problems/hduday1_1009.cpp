/**
  * @Problem hduday1_1009.cpp
  * @Time 2020/7/21 16:52
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 5e4 + 5;

struct node {
    ll pos, speed;
    int flag;

    bool operator<(const node a) {
        if (pos == a.pos) {
            return speed > a.speed;
        }
        return pos > a.pos;
    }
} p[maxn];

int main() {
//    freopen("D://ACM/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].pos, &p[i].speed);
            p[i].flag = 1;
        }
        sort(p, p + n);
        vector<node> v;
        v.push_back(p[0]);
        ll now = p[0].speed;
        if (n > 1) {
            if (p[1].pos == p[0].pos && p[0].speed == p[1].speed) {
                v[0].flag = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (p[i].speed > now) {
                v.push_back(p[i]);
                now = p[i].speed;
                int a = v.size() - 1;
                if (i + 1 < n && v[a].pos == p[i + 1].pos && v[a].speed == p[i + 1].speed) {
                    v[a].flag = 0;
                }
            }
        }

        stack<pair<node, pair<ll, ll>>> s;

        s.push(make_pair(v[0], pair<ll, ll>(0, 0)));

        for (int i = 1; i < v.size(); i++) {
            while (s.size() > 1) {
                pair<node, pair<ll, ll>> now = s.top();
                ll dx = now.first.pos - v[i].pos;
                ll dy = v[i].speed - now.first.speed;
                if (dx * now.second.second == dy * now.second.first) {
                    s.pop();
//                    now.first.flag = 0;
//                    s.push(now);
//                    break;
                } else if (dx * now.second.second > dy * now.second.first) {
                    s.push(make_pair(v[i],
                                     make_pair(now.first.pos - v[i].pos, v[i].speed - now.first.speed)));
                    break;
                } else {
                    s.pop();
                }
            }
            if (s.size() == 1) {
                pair<node, pair<ll, ll>> now = s.top();
                s.push(make_pair(v[i], make_pair(now.first.pos - v[i].pos, v[i].speed - now.first.speed)));
            }
        }

        int ans = 0;
        while (!s.empty()) {
            pair<node, pair<ll, ll>> now;
            now = s.top();
            s.pop();
            ans += now.first.flag;
        }
        printf("%d\n", ans);
    }

    return 0;
}
