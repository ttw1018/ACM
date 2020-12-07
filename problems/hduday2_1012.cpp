/**
  * @Problem hduday2_1012.cpp
  * @Time 2020/7/24 8:16
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

char a[maxn], b[maxn];
int A[maxn], B[maxn];
int g[maxn][27];

int f[27][27];

int n, m;


void solve(int l, int r) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = n + 1;
        }
    }
    f[0][0] = l - 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            f[i + 1][j] = min(f[i + 1][j], f[i][j]);
            if (f[i][j] < r) {
                f[i + 1][j + 1] = min(f[i + 1][j + 1], g[f[i][j] + 1][B[i + 1]]);
            }
        }
    }
    int ans = 0;
    for (int i = m; i >= 0; i--) {
        for (int j = i; j <= m; j++) {
            if (f[j][i] <= r) {
                ans = m + r - l + 1 - 2 * i;
                printf("%d\n", ans);
                return;
            }
        }
    }
    printf("%d\n", m + r - l + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", a + 1, b + 1);
        n = strlen(a + 1);
        m = strlen(b + 1);
        for (int i = 1; i <= n; i++) A[i] = a[i] - 'a';
        for (int i = 1; i <= m; i++) B[i] = b[i] - 'a';
        for (int i = 0; i < 26; i++) g[n + 1][i] = n + 1;
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 26; j++) {
                g[i][j] = g[i + 1][j];
            }
            g[i][A[i]] = i;
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            solve(l, r);
        }
    }


    return 0;
}


