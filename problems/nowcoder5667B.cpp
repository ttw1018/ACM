/**
  * @Problem nowcoder5667B.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/13 20:44
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long double eps = 1e-20;

const int mod = 1e9 + 7;

struct Point {
    ll x, y;

    void in() {
        cin >> x >> y;
    }

    Point operator-(Point p) {
        Point ans;
        ans.x = x - p.x;
        ans.y = y - p.y;
        return ans;
    }
} p[2010];

ll dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

ll dis(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll dis(Point a) {
    return a.x * a.x + a.y * a.y;
}


struct fenshu {
    ll a, b;

    fenshu() {}

    fenshu(ll a, ll b) : a(a), b(b) {}

    bool operator<(const fenshu x) {
        return (__int128) a * x.b < (__int128) b * x.a;
    }

    bool operator==(fenshu x) {
        return (__int128) a * x.b == (__int128) b * x.a;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i].in();
    }

    int ans = 1;
    Point yuan;
    yuan.x = 0;
    yuan.y = 0;
    for (int i = 1; i <= n; i++) {
        vector<fenshu> v;
        for (int j = 1; j <= n; j++) {
            Point p1 = p[i] - yuan;
            Point p2 = p[j] - yuan;
            if (cross(p1, p2) < 0) {
                p1 = yuan - p[j];
                p2 = p[i] - p[j];
                ll fuhao = 1;
                ll fenzi = dot(p1, p2);
                if (fenzi < 0) fuhao = -1;
                fenzi = fenzi * fenzi * fuhao;
                ll fenmu = dis(p1) * dis(p2);
                v.push_back(fenshu(fenzi, fenmu));
            }
        }

        sort(v.begin(), v.end());

        int cnt = 1;
        int l = 0;
        for (int j = 1; j < v.size(); j++) {
            if (v[j] == v[l]) {
                cnt++;
            } else {
                ans = max(ans, cnt + 1);
                l = j;
                cnt = 1;
            };
        }
        if (v.size())
            ans = max(ans, cnt + 1);
    }

    cout << ans << endl;


    return 0;
}
