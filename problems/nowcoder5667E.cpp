#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

const int maxn = 3e5 + 5;

ll A[maxn];
const int N = 1 << 18;

ll ans[maxn];

void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}


void fwt(ll *f, ll inv = 1) {
    for (int len = 2; len <= N; len <<= 1) {
        for (int i = 0; i < N; i += len) {
            for (int j = 0; j < len / 2; j++) {
                ll a = f[i + j], b = f[i + j + len / 2];
                f[i + j] = (a + b) % mod * inv % mod;
                f[i + j + len / 2] = (a - b) % mod * inv % mod;
                MOD(f[i + j]);
                MOD(f[i + j + len / 2]);
            }
        }
    }
}

ll a[maxn], b[maxn];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        ans[1] = max(ans[1], A[i]);
        a[A[i]]++;
    }
    fwt(a);
    for (int i = 0; i < N; i++) {
        A[i] = a[i];
    }

    for (int i = 2; i <= 20; i++) {
        for (int j = 0; j < N; j++) {
            MOD(A[j] = a[j] * A[j] % mod);
            b[j] = A[j];
        }
        fwt(b, mod / 2 + 1);
        for (int j = N - 1; j >= 0; j--) {
            if (b[j]) {
                ans[i] = j;
                break;
            }
        }
    }


    for (int i = 22; i <= n; i++) {
        ans[i] = ans[i - 2];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}
