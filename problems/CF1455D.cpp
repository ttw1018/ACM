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

int a[maxn];
int dp[maxn];


int main () {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        v.push_back(x);
        sort(v.begin(), v.end());
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            dp[a[i]] = 1;
            for (int j = 1; j < i; j++) {
                if (a[j] <= a[i]) {
                    dp[a[i]] = max(dp[a[i]], dp[a[j]] + 1);
                }
            }
            ans = max(ans, dp[a[i]]);
        }
        if (ans == n) {
            cout << 0 << endl;
        }
        else if (ans == n - 1) {
            int pos = -1;
            for (int i = 2; i <= n; i++) {
                if (a[i] < a[i - 1]) {
                    pos = i;
                    break;
                }
            }
            
        }
    }
    return 0;
}