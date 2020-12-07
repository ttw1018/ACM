/**
  * @Problem nowcoder3577A.cpp
  * @Time 2020/7/18 9:31
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {

    int x, y;
    cin >> x >> y;
    if (x == 0) {
        if (y > 0) {
            cout << y << endl;
        } else {
            y = abs(y);
            if (y & 1) {
                cout << y + 2 << endl;
            } else {
                cout << y + 4 << endl;
            }
        }
    } else if (y == 0) {
        if (x > 0) {
            cout << x << endl;
        } else {
            x = abs(x);
            if (x & 1) {
                cout << x + 2 << endl;
            } else {
                cout << x + 4 << endl;
            }
        }
    } else if (x > 0) {
        if (y > 0) {
            if (x & 1) {
                if (y & 1) {
                    cout << x + y + 2 << endl;
                } else {
                    cout << x + y << endl;
                }
            } else {
                cout << x + y << endl;
            }
        } else {
            y = abs(y);
            if (x & 1) {
                cout << x + y << endl;
            } else {
                if (y & 1) {
                    cout << x + y + 2 << endl;
                } else {
                    cout << x + y << endl;
                }
            }

        }
    } else {
        x = abs(x);
        if (y > 0) {
            if (y & 1) {
                cout << x + y << endl;
            } else {
                if (x & 1) {
                    cout << x + y + 2 << endl;
                } else {
                    cout << x + y << endl;
                }
            }

        } else {
            y = abs(y);
            if (x & 1) {
                cout << x + y + 2 << endl;
            } else {
                if (y & 1) {
                    cout << x + y + 1 << endl;
                } else {
                    cout << x + y + 4 << endl;
                }
            }

        }
    }


    return 0;
}
