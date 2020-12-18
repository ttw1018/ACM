//
// Created by ttw on 2020/11/26.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            n += s[i] - '0';
        }
        if (n % 3) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }
    }


    return 0;
}
