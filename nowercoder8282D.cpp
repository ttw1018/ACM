#include <iostream>
#include <vector>

using namespace std;

const int maxn = 5e4 + 5;

int mu[maxn];
int prime[maxn];
bool vis[maxn];
int tot = 0;
int sum[maxn];

void init () {
    mu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            else mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i < maxn; i++) {
        sum[i] = sum[i - 1] + mu[i];
    }
}

vector<int> v[maxn];
int ans[maxn];

int get(int l, int r, int d) {
    if (l == 1) return v[d][r - 1];
    return v[d][r - 1] - v[d][l - 2];
}

int main () {
    init();
    for (int i = 1; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            v[i].push_back(mu[j]);
        }
    }

    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < v[i].size(); j++) {
            v[i][j] += v[i][j - 1];
        }
    }

    ans[1] = 1;
    for (int i = 2; i < maxn; i++) {
        ans[i] = ans[i - 1];
        ans[i] += mu[i] * mu[i] * mu[i];

        ans[i] += mu[1] * get(1, i, 1) * get(1, i, 1);
        ans[i] -= mu[1] * get(1, i - 1, 1) * get(1, i - 1, 1);


        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ans[i] -= mu[j] * get(1, i / j - 1, j) * get(1, i / j - 1, j);
                ans[i] += mu[j] * get(1, i / j, j) * get(1, i / j, j);
                if (j * j != i) {
                    ans[i] -= mu[i / j] * get(1, j - 1, i / j) * get(1, j - 1, i / j);
                    ans[i] += mu[i / j] * get(1, j, i / j) * get(1, j, i / j);
                }
            }
        }
    }






    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
//        int res = 0;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                res += mu[i * j];
//            }
//        }
//        cout << res << endl;
//        cout << endl;
    }


}
