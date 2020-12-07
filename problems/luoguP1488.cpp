/**
  * @Problem luoguP1488.cpp
  * @Time 2020/7/18 8:11
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (abs(b - a) == 1) cnt++;
    if (abs(c - b) == 1) cnt++;
    if (a == 0 && c == n - 1) cnt++;
    if (cnt >= 2) {
        cout << "JMcat Win" << endl;
        return 0;
    }

    if (n & 1) {
        cout << "PZ Win" << endl;
    } else
        cout << "JMcat Win" << endl;


    return 0;
}
