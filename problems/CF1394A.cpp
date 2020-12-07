/**
  * @Problem CF1394A.cpp
  * @Time 2020/8/12 22:33
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

bool check(int a, int b, int c, int d) {
    int cnt = 0;
    if (a & 1) cnt++;
    if (b & 1) cnt++;
    if (c & 1) cnt++;
    if (d & 1) cnt++;
    return cnt <= 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (check(a, b, c, d)) {
            cout << "YES" << endl;
            continue;
        }
        if (a > 0 && b > 0 && c > 0) {
            a--;
            b--;
            c--;
            d += 3;
            if (check(a, b, c, d)) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;

    }


    return 0;
}
