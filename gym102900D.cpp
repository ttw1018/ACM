//
// Created by ttw on 2020/12/16.
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
//const int maxn = 2e5 + 5;

double n;
double p1, p2, v1, v2;

double eps = 1e-8;


bool check (double x) {
    double x1 = x * v1;
    double x2 = x * v2;

//    printf("%.10f %.10f\n", x1, x2);
    if (x1 >= n - p1 && x2 >= p2) return true;

    double l = 0;
    if (x1 >= p1)  {
        l = max(p1 + (x1 - p1) / 2, x1 - p1);
    }

    double r = n;

    if (x2 >= (n - p2)) {
        r = min(p2 - (x2 - (n - p2)) / 2, n - (x2 - (n - p2))) ;
    }
    if (r <= l) return true;

    return false;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> p1 >> v1 >> p2 >> v2;
        if (p1 > p2) {
            swap(p1, p2);
            swap(v1, v2);
        }

        double l = 0, r = 1e8;
        while (r - eps > l) {
            double m = (l + r) / 2;
            if (check(m)) {
                r = m;
            }
            else {
                l = m + eps;
            }
        }
        printf("%.8f\n", l);
    }

    return 0;
}
