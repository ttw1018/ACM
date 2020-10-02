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

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll sum[35];

ll get (ll x) {
    return x * (x + 1) / 2;
}

int main () {
    for (int i = 1; i <= 31; i++) {
        sum[i] = sum[i - 1] + get(pow(ll(2), i) - 1);
    }
    cout << endl;
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        int ans = 0;
        for (int i = 1; i <= 31; i++) {
            if (x >= sum[i]) {
                ans = i;
            }
            else {
                break;
            }
        }
        cout << ans << endl;
        
    }



    return 0;
}