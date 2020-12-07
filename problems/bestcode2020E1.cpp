/**
  * @Problem bestcode2020E1.cpp
  * @Time 2020/7/19 15:38
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll qp(ll a, ll b) {
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int A[105];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

    }


    return 0;
}
