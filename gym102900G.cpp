//
// Created by ttw on 2020/12/16.
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
//const int maxn = 2e5 + 5;


int main () {
    ll n;
    cin >> n;
    ll x = n / 3;
    ll res = n - x;
    ll ans = (n * n - res * res + res - n) / 2;
    cout << ans << endl;

    return 0;
}
