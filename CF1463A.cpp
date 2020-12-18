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
//const int maxn = 2e5 + 5;


int main () {
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll sum = (a + b + c) / 9;
        ll ss = a + b + c;
        ll mi = min(a, min(b, c));
        if (mi < sum || ss % 9) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


    return 0;
}
