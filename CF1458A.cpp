/*
*   FileName: CF1458A
*   Author: ttw
*   Time: 5:35 下午:2020/12/19
*/

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
const int maxn = 2e5 + 5;


ll gcd (ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll a[maxn], b[maxn], c[maxn];

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> b[j];
    }
    if (n == 1) {
        for (int i = 1; i <= m; i++) {
            cout << a[1] + b[i]  << " ";
        }
        cout << endl;
        return 0;
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i < n; i++) {
        c[i] = a[i + 1] - a[i];
    }

    ll gc = c[1];
    for (int i = 2; i < n; i++) {
        gc = gcd(gc, c[i]);
    }

    for (int i = 1; i <= m; i++) {
        ll x = a[1] + b[i];
        ll y = a[2] + b[i];
        ll ggc = gcd(x, y);
        cout << gcd(gc, ggc) << endl;
    }


    return 0;
}
