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


// const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n, k;

int v[maxn];
int dp[maxn];

vector<pair<int, int>> e[maxn];

ll ans = 0;

void dfs(int x, int fa) {
    // cout << x << endl;
    dp[x] += v[x];
    for (auto i : e[x]) {
        int to = i.first;
        int val = i.second;
        if (to == fa) {
            continue;
        } 
        dfs(to, x);
        dp[x] += dp[to];
        if (dp[to] % k == 0)  {
            ans -= val;
        }
    }
    
}


int main () {

    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
        ans += z;
    }
    dfs(1, 0);
    cout << ans << endl;
    
    
    return 0;
}