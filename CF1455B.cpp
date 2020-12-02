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
const int maxn = 1e6 + 5;

int ans[maxn * 3];


int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int now = 0;
        int ans = 0;
        for (int i = 1; i <= 2000; i++) {
            now += i;
            if (now >= n) {
                ans = i;
                break;
            }
        }
        now -= n;
        if (now == 0) cout << ans << endl;
        else if (now > 1 && now <= ans + 1) cout << ans << endl;
        else cout << ans + 1 << endl;
        
        
    }
    
    
    
    
    return 0;
}