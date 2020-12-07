/**
  * @Problem hduday7_1009.cpp
  * @Time 2020/8/11 12:21
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

int ans[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        if (x + y > n + 1) {
            printf("NO\n");
            continue;
        }

        for (int i = 0; i < y; i++) {
            ans[n - i] = n - y + i + 1;
        }

        int all = n - y;
        int de = all - (x - 1);
        if (de > x - 1) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        for (int i = 1; i <= all - de * 2; i++) ans[i] = i;

        for (int i = all - de * 2 + 1; i <= all; i += 2) {
            ans[i] = i + 1;
            ans[i + 1] = i;
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%s", ans[i], i == n ? "\n" : " ");
        }

    }


    return 0;
}
