/**
  * @Problem hdu2020day1D.cpp
  * @Time 2020/7/21 12:38
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int T;
    scanf("%d", &T);

    int A[5];
    A[1] = 26;
    A[2] = 26 * 26;
    A[2] = 26 * 26 * 26;
    A[4] = 26 * 25 * 24;
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n <= 3) {
            printf("%d\n", A[n]);
        } else {
            printf("%d\n", A[4]);
        }
    }

    return 0;
}
