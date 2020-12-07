/**
  * @Problem nowcoder5668L.cpp
  * @Time 2020/7/18 12:04
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int flag = 1;
    if (s[0] != 'l' && s[0] != 'L') {
        flag = 0;
    }
    if (s[1] != 'o' && s[1] != 'O') {
        flag = 0;
    }
    if (s[2] != 'v' && s[2] != 'V') {
        flag = 0;
    }
    if (s[3] != 'e' && s[3] != 'E') {
        flag = 0;
    }
    if (s[4] != 'l' && s[4] != 'L') {
        flag = 0;
    }
    if (s[5] != 'y' && s[5] != 'Y') {
        flag = 0;
    }

    if (flag) {
        cout << "lovely" << endl;
    } else {
        cout << "ugly" << endl;
    }


    return 0;
}
