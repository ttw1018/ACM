/**
  * @Problem hduday4_1011.cpp
  * @Time 2020/7/30 12:50
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

const double G = 6.67430e-11;


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double a, b, d, t;
        cin >> a >> b >> d >> t;

        double aa = G * (a + b) / (d * d * 1e6);

        double dd = 0.5 * aa * t * t / 1000;

        cout << fixed << setprecision(12) << d - dd << endl;


    }


    return 0;
}
