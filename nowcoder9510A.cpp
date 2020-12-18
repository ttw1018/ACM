//
// Created by ttw on 2020/12/13.
//


#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
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


int main () {
    string s;
    cin >> s;

    ll now = 0;
    vector<ll> v1;
    vector<char> v2;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            now = now * 10 + s[i] - '0';
        }
        else {
            v2.push_back(s[i]);
            v1.push_back(now);
            now = 0;
        }
    }
    v1.push_back(now);
//    for (auto i : v1) {
//        cout << i << " ";
//    }
//    cout << endl;

    for (int i = v2.size() - 1; i >= 0; i--) {
        if (v2[i] == '^') {
            v2.erase(v2.begin() + i);
            v1[i] = v1[i] ^  v1[i + 1];
            v1.erase(v1.begin() + i + 1);
        }
    }
//    for (auto i : v1) {
//        cout << i << " ";
//    }
//    cout << endl;
//    for (auto i : v2) {
//        cout << i << " ";
//    }
//    cout << endl;
    now = v1[0];
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] == '+') {
            now = now + v1[i + 1];
        }
        else {
            now = now - v1[i + 1];
        }
    }
    cout << now << endl;





    return 0;
}
