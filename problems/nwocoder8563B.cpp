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
    int n, k;
    cin >> n >> k;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
    ll ans = 0;
    while (q.size()) {
        int now = q.top();
        q.pop();
        if (now & 1) ans += now;
        else {
            if (k > 0) {
                q.push(now / 2);
                k--;
            }
            else {
                ans += now;
            }
        }
    }
    cout << ans << endl;
    
    
    
    
    
    
    return 0;
}
