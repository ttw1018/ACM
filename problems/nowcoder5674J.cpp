/**
  * @Problem nowcoder5674J.cpp
  * @Time 2020/8/8 16:42
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 505;
int a[maxn][maxn];

int line[maxn][maxn][maxn];
int sum[maxn][maxn];

int w[maxn * maxn * 10];

const int N = maxn * maxn;

int check(int d, int u, int l, int r) {

    if (d == u - 1 || l == r - 1) return 0;
    u--, r--;

    int all = sum[u][r] - sum[u][l] - sum[d][r] + sum[d][l];
    return all;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j])
                sum[i][j] = sum[i][j - 1] + 1;
            else
                sum[i][j] = sum[i][j - 1] - 1;
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            sum[i][j] += sum[i - 1][j];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                for (int k = j + 1; k <= m; k++) {
                    if (a[i][k] == 1) {
                        line[i][j][k] = 1;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int now = 0, cnt = 0;
            vector<int> v;
            for (int k = 1; k <= n; k++) {
                if (a[k][i] == 0 || a[k][j] == 0) {
                    for (auto z : v) {
                        w[z]--;
                    }
                    v.clear();
                    cnt = 0;
                    continue;
                }
                if (line[k][i][j]) {
                    if (cnt > 0) {
                        int val = check(now, k, i, j);
                        if (abs(val) <= 1) {
//                            cout << i << " " <<  j << " " << now << " " << k << endl;
                            ans++;
                        }
//                        cout << ans << " ";
                        ans += w[N + val - (j - i - 1)] + w[N + val - (j - i - 1) - 1] + w[N + val - (j - i -
                                                                                                      1) + 1];
//                        cout << ans <<endl;
                        w[val + N]++;
                        v.push_back(val + N);
                    } else {
                        now = k;
                        cnt = 1;
                    }
                }
            }
            for (auto z : v) {
                w[z]--;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
