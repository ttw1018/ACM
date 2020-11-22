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


int main () {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll a;
        int cnt = 0;
        ll sum = 0;
        ll ma = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            sum += a;
            if (a == 0) cnt++;
            ma = max(a, ma);
        }
        ll ans = ma * (n - 1) - sum;
        while (ans < 0) ans += n - 1;
        cout << ans << endl;

        
    }
    
    
    
    
    return 0;
}