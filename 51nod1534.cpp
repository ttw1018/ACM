//
// Created by ttw on 2020/11/26.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;


#define B cout << "Vasiliy" << endl; return 0;
#define A cout << "Polycarp" << endl; return 0;

int d1(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int d2(int x1, int y1, int x2, int y2) {
    int x = abs(x2 - x1);
    int y = abs(y2 - y1);
    return min(x, y) + abs(x - y);
}


int main() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x2 < x1 && y2 < y1) {
        B;
    }

    if (x2 >= x1) {
        if (d2(x2, y2, x1, 0) < d1(x1, y1, x1, 0)) {
            B;
        }
    }
    if (y2 >= y1) {
        if (d2(x2, y2, 0, y1) < d1(x1, y1, 0, y1)) {
            B;
        }
    }
    A;


    return 0;
}
