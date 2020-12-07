/**
  * @Problem hduday6_1009.cpp
  * @Time 2020/8/6 12:13
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        if ((n - 1) % m) {
            cout << "F\n";
        } else {
            cout << "T\n";
        }
    }


    return 0;
}
