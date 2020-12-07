/**
  * @Problem nowcoder5671G.cpp
  * @Time 2020/7/27 16:14
  *
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int ans1[205][205], ans2[205][205];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int all = 2 * n * (n + 1);
        if (all % k || n == 1 || k == 1) {
            printf("-1\n");
            continue;
        }
        int cnt = all / k;
        int now = 1;
        int ccnt = 0;

        for (int i = 1; i <= n + 1; i++) {
            if (i & 1) {
                for (int j = 1; j <= n; j += 2) {
                    ans1[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }
            } else {
                for (int j = 2; j <= n; j += 2) {
                    ans1[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }

            }
        }
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                for (int j = 1; j <= n + 1; j += 2) {
                    ans2[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }
            } else {
                for (int j = 2; j <= n + 1; j += 2) {
                    ans2[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }

            }
        }
        for (int i = 1; i <= n + 1; i++) {
            if (!(i & 1)) {
                for (int j = 1; j <= n; j += 2) {
                    ans1[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }
            } else {
                for (int j = 2; j <= n; j += 2) {
                    ans1[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }

            }
        }
        for (int i = 1; i <= n; i++) {
            if (!(i & 1)) {
                for (int j = 1; j <= n + 1; j += 2) {
                    ans2[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }
            } else {
                for (int j = 2; j <= n + 1; j += 2) {
                    ans2[i][j] = now;
                    ccnt++;
                    if (ccnt == cnt) {
                        now++;
                        ccnt = 0;
                    }
                }

            }
        }
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans1[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans2[j][i] << " ";
            }
            cout << endl;
        }


    }

    return 0;
}
