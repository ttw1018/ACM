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
const int maxn = 2e5 + 5;

char s[maxn];

int dp[maxn];


int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        stack<int> v1, v2;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (s[i] == '[') v1.push(i);
            else if (s[i] == '(') v2.push(i);
            else if (s[i] == ']') {
                if (v1.size()) {
                    ans++;
                    v1.pop();
                }
            }
            else {
                if (v2.size()) {
                    ans++;
                    v2.pop();
                }
            }
            
        }
        cout << ans << endl;
        
    }
    
    
    
    
    return 0;
}