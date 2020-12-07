/**
  * @Problem nowcoder5666D.cpp
  * @Time 2020/7/16 17:27
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

ll A[205][405], B[205];

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}


void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}


int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                A[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
            }
            A[i][n + i] = 1;
        }
        for (int i = 1; i <= n; i++) cin >> B[i];

        for (int i = 1; i <= n; i++) {
            int c = i;
            for (int j = i; j <= n; j++) {
                if (A[j][i]) {
                    c = j;
                    break;
                }
            }
            swap(A[i], A[c]);
            ll inv = qp(A[i][i], mod - 2);
            for (int j = i; j <= 2 * n; j++) {
                A[i][j] = A[i][j] * inv % mod;
                MOD(A[i][j]);
            }


            for (int j = i + 1; j <= n; j++) {
                for (int k = 2 * n; k >= i; k--) {
                    A[j][k] = A[j][k] - A[i][k] * A[j][i];
                    MOD(A[j][k]);
                }
            }
        }


        for (int i = n; i >= 1; i--) {
            for (int j = i - 1; j >= 1; j--) {
                for (int k = 2 * n; k >= i; k--) {
                    A[j][k] -= A[j][i] * A[i][k];
                    MOD(A[j][k]);
                }
            }
        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= 2 * n; j++) {
//                cout << A[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans += B[i] * B[j] * A[i][n + j];
                MOD(ans);
            }
        }
        cout << ans << endl;
    }


    return 0;
}
