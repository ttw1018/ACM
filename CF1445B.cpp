//
// Created by ttw on 2020/11/1.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << max(a + b, c + d) << endl;
    }



    return 0;
}
