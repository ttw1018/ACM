// #pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

ll qp (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

ll a[maxn];

struct shield {
    ll a, b;
} s[maxn];



int main () {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    
    




    return 0;
}