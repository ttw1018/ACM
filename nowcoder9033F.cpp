//
// Created by ttw on 2020/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

const int mod = 998244353;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

ll get(ll a1, ll q) {
    return qp(1 - q + mod, mod - 2) * a1 % mod;
}

int main() {

    int a, b, p;

    cin >> a >> b >> p;
    if (p == 1) {
        cout << 1 << endl;
        return 0;
    }

    ll x = p * (1 - p + mod) % mod;

    int a1 = qp(x, a - b - 1 / 2)

    return 0;
}