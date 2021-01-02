//
// Created by ttw on 2020/12/18.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;


int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        vector<int> L, R;
        for (int i = 1; i <= n ;i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
            L.push_back(a);
            R.push_back(b);
        }
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        int ans = 0;
        for (auto a : v) {
            int l = a.first, r = a.second;
//            cout << l << " " << r << endl;
            int k = lower_bound(R.begin(), R.end(), l) - R.begin();
            int all = upper_bound(L.begin(), L.end(), r) - L.begin();
//            cout << k << " " << all << endl;
            ans = max(ans, all - k);
        }
        cout << n - ans << endl;


    }



    return 0;
}
