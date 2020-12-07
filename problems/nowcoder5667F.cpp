/**
  * @Problem nowcoder5667F.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/13 13:05
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 5e3 + 5;
int A[maxn][maxn];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int xma[maxn][maxn];


int main() {

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = A[j][i] = i * j / gcd(i, j);
        }
    }

    int ma = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = 0;
        int q[maxn];
        q[r] = 1;
        for (int j = 1; j <= m; j++) {
            ma = max(ma, A[i][j]);
            while (A[i][j] >= A[i][q[r]] && r >= l) r--;
            q[++r] = j;
            while (j - q[l] >= k) l++;
            if (j >= k) {
                xma[i][j - k + 1] = A[i][q[l]];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m - k + 1; i++) {
        int l, r;
        int q[maxn];
        l = 1, r = 0;
        for (int j = 1; j <= n; j++) {
            while (xma[j][i] >= xma[q[r]][i] && r >= l) r--;
            q[++r] = j;
            while (j - q[l] >= k) ++l;
            if (j >= k) ans += xma[q[l]][i];
        }
    }
    cout << ans << endl;


    return 0;
}
