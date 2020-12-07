/**
  * @Problem CF1384A.cpp
  * @Time 2020/7/24 22:30
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a;
        char s[150];
        for (int i = 0; i < 150; i++) {
            s[i] = 'a' + i % 26;
        }
        for (int j = 0; j < 150; j++) {
            cout << s[j];
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (s[a] < 'z') {
                s[a] += 1;
            } else {
                s[a] -= 1;
            }
            for (int j = 0; j < 150; j++) {
                cout << s[j];
            }
            cout << endl;
        }

    }


    return 0;
}
