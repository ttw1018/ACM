/**
  * @Problem nowcoder5667K.cpp
  * @Time 2020/7/17 11:32
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const ld pi = acos(-1);


ld cal(ld x1, ld y1, ld x2, ld y2) {
    return abs(0.5 * (x1 * y2 - y1 * x2));
}

int main() {
    int T;
    cin >> T;
    ld co[500], si[500];
    for (int i = 0; i < 500; i++) {
        si[i] = sin(i * pi / 250);
        co[i] = cos(i * pi / 250);
    }
    while (T--) {
        ld a[3];
        for (int i = 0; i < 3; i++) cin >> a[i];
        sort(a, a + 3);

        ld ans = 0;
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                ld x1 = a[0], y1 = 0;
                ld x2 = a[1] * co[i], y2 = a[1] * si[i];
                ld x3 = a[2] * co[j], y3 = a[2] * si[j];
                ans += cal(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
            }
        }

        ans /= 250000;
//        cout << ans << endl;
//        ll x = ans * 100;
//        if (x % 10 >= 5) ans += 0.1;
        cout << setprecision(1) << fixed << ans << endl;

    }


    return 0;
}
