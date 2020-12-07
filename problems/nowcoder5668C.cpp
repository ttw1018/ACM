/**
  * @Problem nowcoder5668C.cpp
  * @Time 2020/7/18 12:53
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const double eps = 1e-3;

struct Point {
    double a, b;

    void in() {
        cin >> a >> b;
    }

    Point operator-(const Point x) {
        Point ans;
        ans.a = a - x.a;
        ans.b = b - x.b;
        return ans;
    };

    double dis(Point x) {
        double dx = a - x.a, dy = b - x.b;
        return sqrt(dx * dx + dy * dy);
    }

} p[30];


bool check(double a, double b) {
    if (abs(a * 9 - b * 6) < eps) {
        return true;
    }
    return false;
}

double cross(Point a, Point b) {
    return a.a * b.b - a.b * b.a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 20; i++) {
            p[i].in();
        }

        vector<Point> v;
        for (int i = 0; i < 20; i++) {
            int l = (i - 1 + 20) % 20;
            int r = (i + 1) % 20;
            double d1 = p[i].dis(p[l]);
            double d2 = p[i].dis(p[r]);

            if (check(d1, d2)) {
                v.push_back(p[l] - p[i]);
                v.push_back(p[r] - p[i]);
                break;
            }
            if (check(d2, d1)) {
                v.push_back(p[r] - p[i]);
                v.push_back(p[l] - p[i]);
                break;
            }
        }

        if (cross(v[0], v[1]) < 0) {
            cout << "right" << endl;
        } else {
            cout << "left" << endl;
        }

    }


    return 0;
}
