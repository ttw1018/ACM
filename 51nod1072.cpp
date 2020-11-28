//
// Created by ttw on 2020/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;


int main () {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        double s5 = sqrt(5);
        cout.precision(50);
        cout << (s5 + 1) / 2 << endl;
        cout << s5 << endl;
        if (ll (s5 + 1) * y == ll(s5 + 3) * x) cout << "B" << endl;
        else cout << "A" << endl;

    }


    return 0;
}

