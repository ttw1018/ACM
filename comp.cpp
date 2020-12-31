/**
  * @Problem comp.cpp
  * @Time 2020/7/21 16:06
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    ifstream f1("D://ACM/out", ios::in);
    ifstream f2("D://ACM/out1", ios::in);

    string s1, s2;
    int cnt = 0;
    while (getline(f1, s1) && getline(f2, s2)) {
        cnt++;
        if (s1 != s2) {
            cout << s1 << " " << s2 << endl;
        }
    }
    cout << cnt << endl;

    return 0;
}
