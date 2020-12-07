/**
  * @Problem hdu2020day2_1006.cpp
  * @Time 2020/7/23 15:51
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2e6 + 5;

ll f[maxn];

int main() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 2e6 + 4; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        scanf("%d", &a);
        ll A = 0, B = 0, C = 0;
        for (int i = 1; i <= a; i++) {
            int sta;
            scanf("%d", &sta);
            if (sta) A = A + f[i];
        }
        scanf("%d", &b);
        for (int i = 1; i <= b; i++) {
            int sta;
            scanf("%d", &sta);
            if (sta) B = B + f[i];
        }
        scanf("%d", &c);
        for (int i = 1; i <= c; i++) {
            int sta;
            scanf("%d", &sta);
            if (sta) C = C + f[i];
        }


        ll all = A * B;

        for (int i = 1; i <= a + b + 1; i++) {
            if (f[i] + C == all) {
                printf("%d\n", i);
                break;
            }
        }

    }

    return 0;
}
