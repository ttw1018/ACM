/**
  * @Problem bestcode2020C1.cpp
  * @Time 2020/7/19 15:18
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}


int sum[1005][1005];
int dp[1005][1005];

void init() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (gcd(i, j) == 1) {
                sum[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + sum[i][j];
        }
    }

};

int main() {

    init();

    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < b) swap(a, b);


        printf("%d\n", dp[a][b]);
    }


    return 0;
}
