/**
  * @Problem CF1400A.cpp
  * @Time 2020/8/25 22:32
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

char c[500];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n - 1; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < 2 * n - 1; i += 2) {
            cout << c[i];
        }
        cout << endl;
    }


    return 0;
}
