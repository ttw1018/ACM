//
// Created by ttw on 2020/12/17.
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

int a[maxn];

int get (int x) {
    int cnt = -1;
    while (x) {
        cnt++;
        x >>= 1;
    }
    cnt = max(1, 1 << cnt);
    return cnt;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int ans = get(a[i]);
            s1 += a[i];
            s2 += abs(a[i] - ans);
            cout << ans << " ";
        }
        cout << endl;
    }


    return 0;
}
