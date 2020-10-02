#pragma clang diagnostic ignored "-Wdeprecated-declarations"
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
const int maxn = 1e6 + 5;

int a;

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int mi = n;
        ll ans = k - 1;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &a);
            ans += 2 * abs(k - a);
            mi = min(mi, a);
        }
        
        ans -= abs(k - mi);
        ans += mi - 1;
        printf("%lld\n", ans);
        
        
    }
    



    return 0;
}