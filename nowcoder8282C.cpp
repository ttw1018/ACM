//
// Created by ttw on 2020/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

using namespace std;

const int maxn = 1e6 + 5;

int a[maxn];
struct point {
    double x, y;

    point (double a = 0, double b = 0) : x(a), y(b) {}

    point operator - (const point a) {
        return point(x - a.x, y - a.y);
    }
};

point st[maxn];

double cross (point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int main () {

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[1] << endl;
        return 0;
    }

    int cnt = 0;

    st[cnt] = point(1, a[1]);
    st[++cnt] = point(2, a[2]);

    for (int i = 3; i <= n; i++) {
        while(cnt >= 1) {
            point aa = point(i, a[i]) - st[cnt];
            point b = st[cnt - 1] - st[cnt];
            if (cross(aa, b) < 0) cnt--;
            else break;
        }
        st[++cnt] = point(i, a[i]);
    }

//    for (int i = 0; i <= cnt; i++) {
//        cout << st[i].x << " " << st[i].y << endl;
//    }

    double ans = 0;

    for (int i = 1; i <= cnt; i++) {
        ans += (st[i].x - st[i - 1].x + 1) * (st[i].y + st[i - 1].y) / 2.0;
    }
    for (int i = 1; i < cnt; i++) {
        ans -= st[i].y;
    }

    printf("%.1f000000000000\n", ans);


    return 0;
}

