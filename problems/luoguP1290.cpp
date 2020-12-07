/**
  * @Problem luoguP1290.cpp
  * @Time 2020/7/18 8:52
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

bool solve(int a, int b) {
    if (b == 0) return false;
    if (a / b == 1) return !solve(b, a % b);
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        int flag = 1;
        if (solve(a, b)) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
    }


    return 0;
}
