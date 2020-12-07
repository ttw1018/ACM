/**
  * @Problem hdu6798.cpp
  * @Time 2020/7/31 9:21
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

const long double eps = 1e-8;
int L, x, y, vx, vy, k;


bool check(long double t) {
    long double h = sqrt(3) * L / 2;
    long double x1 = x + t * vx;
    long double y1 = y + t * vy;

    ll cnt = 0;

    if (y1 > 0) {
        cnt += floor(y1 / h);
    } else {
        cnt += floor((-y1) / h) + 1;
    }


    long double l1 = -y / sqrt(3) + x;
    long double r1 = -y1 / sqrt(3) + x1;

    l1 += L / 2;
    r1 += L / 2;

    if (l1 > r1) swap(l1, r1);

    if (l1 * r1 < 0) {
        l1 = abs(l1);
        r1 = abs(r1);
        cnt += floor(r1 / L) + floor(l1 / L) + 1;
    } else {
        l1 = abs(l1);
        r1 = abs(r1);
        cnt += abs(floor(l1 / L) - floor(r1 / L));
    }


    l1 = y / sqrt(3) + x;
    r1 = y1 / sqrt(3) + x1;

    l1 += L / 2;
    r1 += L / 2;

    if (l1 > r1) swap(l1, r1);

    if (l1 * r1 < 0) {
        l1 = abs(l1);
        r1 = abs(r1);
        cnt += floor(r1 / L) + floor(l1 / L) + 1;
    } else {
        l1 = abs(l1);
        r1 = abs(r1);
        cnt += abs(floor(l1 / L) - floor(r1 / L));
    }

    return cnt >= k;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> L >> x >> y >> vx >> vy >> k;

        long double l = 0, r = 1e10;

        while (r - l > eps) {
//            cout << l << " " << r << endl;
            long double mid = (r + l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + eps;
            }
        }
        cout << fixed << setprecision(8) << r << endl;

    }
    return 0;
}
