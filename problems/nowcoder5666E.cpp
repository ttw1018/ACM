/**
  * @Problem nowcoder5666E.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/12 20:16
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int A[maxn];

int t[maxn];

int lowbit(int x) { return x & (-x); }

void upd(int x) {
    while (x > 0) {
        t[x]++;
        x -= lowbit(x);
    }
}

int query(int x) {
    return t[x];
}


int main() {
    ll n, m, mod;
    while (cin >> n >> m >> mod) {
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        sort(A + 1, A + 1 + n);
        ll ans = 1;
        for (int i = 1; i < n; i++) {
            ans = ans * A[i] % mod;
        }
        for (int i = 1; i <= m + 1; i++) t[i] = 0;
        for (int i = 1; i <= n; i++) {
            t[1]++;
            t[A[i] + 1]--;
        }
        ll now = t[1];
        for (int i = 2; i <= m; i++) {
            now += t[i];
            ans = ans * now % mod;
        }

        cout << ans << endl;
    }


    return 0;
}
