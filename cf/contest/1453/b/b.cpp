#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 2e5 + 5;
ll a[maxn];
ll dp[maxn];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        ll ma = 0;
        ll sum = 0;
        
        for (int i = 2; i <= n; i++) {
            sum += abs(a[i] - a[i - 1]);
        }
        
        ma = abs(a[2] - a[1]);
        ma = max(ma, abs(a[n] - a[n - 1]));
        for (int i = 2; i < n; i++) {
            ma = max(ma, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i - 1]));
        }
        cout << sum - ma << endl;
        
        
        
    }
    

    return 0;
}