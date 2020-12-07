/**
  * @Problem hduday3_1008.cpp
  * @Time 2020/7/28 15:08
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const int mod = 1e9 + 7;

ld line(ld x1, ld y1, ld x2, ld y2) {
    return (y2 - y1) / (x1 - x2);
}


bool solve1(ld x, ld y, ld vx, ld vy) {
    ld a = vy / vx;
    ld b = y - x * a;

    ld a1 = -sqrt(3);
    ld b1 = sqrt(3) / 2;

    ld x0 = line(a, b, a1, b1);
    ld y0 = a * x0 + b;

    if (x0 < -0.5 || x0 > 0.5) {
        return false;
    }

    a = 1 / sqrt(3);
    b = y - a * x;

    ld x1 = line(a, b, a1, b1);
    ld x2 = a * x1 + b;


    return true;


}

int main() {


    return 0;
}


