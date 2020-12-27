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

const int maxn = 1e5 + 5;

int main()
{
    int t;
    cin >> t;
    
    
    while (t--) {
        ll k;
        cin >> k;
        if (k & 1) {
            cout << -1 << endl;
            continue;
        }
        
        vector<int> ans; 

        for (int i = 62; i >= 0; i--) {
            if (k & (ll(1) << i)) {
                ans.push_back(i);
            }
        }
        
        vector<int> v;
        
        for (auto i : ans) {
            if (i > 2) {
                v.push_back(1);
                for (int j = 0; j < i - 2; j++) {
                    v.push_back(0);
                }
                v.push_back(1);
            }
            else {
                for (int j = 0; j < i; j++) {
                    v.push_back(1);
                }
            }
        }
        
        cout << v.size() << endl;
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}