/**
  * @Problem CF1380D.cpp
  * @Time 2020/7/21 11:28
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;
int A[maxn], B[maxn];

vector<int> v[maxn];

int main() {
    int n, m;
    ll x, k, y;
    cin >> n >> m;
    cin >> x >> k >> y;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    B[0] = 0;
    B[m + 1] = 0;
    int i = 1, j = 1;

    while (i <= n && j <= m) {
        if (A[i] == B[j]) {
            j++;
        } else {
            v[j].push_back(A[i]);
        }
        i++;
    }

    while (i <= n) {
        v[j].push_back(A[i]);
        i++;
    }
    if (j != m + 1) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= m + 1; i++) {
        int siz = v[i].size();
        if (siz == 0) continue;
        int cnt = 0;
        int bo = max(B[i], B[i - 1]);
        for (auto j : v[i]) {
//            cout << j << " ";
            cnt += j > bo;
        }
//        cout << endl;
        if (siz < k) {
            if (cnt) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (x >= k * y) {
            if (cnt == 0) {
                ans += siz * y;
            } else {
                ans += x + (siz - k) * y;
            }
        } else {
            ans += siz / k * x + y * (siz - siz / k * k);
        }
//        cout << "ans: " << ans << endl;
    }
}

