/**
  * @Problem luoguP4717.cpp
  * @Time 2020/7/15 12:39
  *
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

const int maxn = 1e6 + 5;

ll A[maxn], B[maxn];
ll a[maxn], b[maxn];
int n;


void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}


void OR(ll *f, ll sta = 1) {
    for (int len = 2; len <= n; len <<= 1) {
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; j++) {
                f[i + j + len / 2] += f[i + j] * sta;
                MOD(f[i + j + len / 2]);
            }
        }
    }
}

void AND(ll *f, ll sta = 1) {
    for (int len = 2; len <= n; len <<= 1) {
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; j++) {
                f[i + j] += f[i + j + len / 2] * sta;
                MOD(f[i + j]);
            }
        }
    }
}


void XOR(ll *f, ll sta = 1) {
    for (int len = 2; len <= n; len <<= 1) {
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; j++) {
                f[i + j] += f[i + j + len / 2];
                f[i + j + len / 2] = f[i + j] - 2 * f[i + j + len / 2];
                f[i + j] *= sta;
                f[i + j + len / 2] *= sta;
                MOD(f[i + j]);
                MOD(f[i + j + len / 2]);
            }
        }
    }
}


void get(ll *a, ll *b) {
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
        MOD(a[i]);
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        a[i] = A[i];
        b[i] = B[i];
    }
}

int main() {
    cin >> n;
    n = 1 << n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    init();
    OR(a);
    OR(b);

    get(a, b);
    OR(a, -1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    init();
    AND(a);
    AND(b);

    get(a, b);
    AND(a, -1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    init();
    XOR(a);
    XOR(b);
    get(a, b);
    XOR(a, 499122177);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}
