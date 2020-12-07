/**
  * @Problem CF1449A.cpp.c
  * @Time 2019/12/6 22:18
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> v;
        for (auto i : s) {
            v.push_back(i);
        }
        sort(v.begin(), v.end());

        for (auto i : v) {
            cout << i;
        }
        cout << endl;
    }




    return 0;
}


