//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
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

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

ll dp[maxn], sum[maxn];


int main () {
    int n;
    cin >> n;
    
    ll inv = qp(2, mod - 2);
    ll inv4 = qp(4, mod - 2);
    ll inv8 = qp(8, mod - 2);

    dp[0] = 1;
    sum[0] = 1;

    dp[1] = inv;
    sum[1] = dp[1];

    dp[2] = inv * inv % mod;
    sum[2] = (dp[2] + dp[0] * inv4 % mod) % mod;

    dp[3] = inv * inv % mod;
    sum[3] = sum[1] + dp[3];

    for (int i = 3; i <= n; i++) {
        dp[i] = sum[i - 1] * inv % mod;
        sum[i] = (sum[i - 2] * inv4 + dp[i]) % mod;
    }
    cout << dp[n] << endl;
    
    
    return 0;
}