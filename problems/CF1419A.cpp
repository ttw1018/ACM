//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;


int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c1, c2, c3, c4;
        c1 = c2 = c3 = c4 = 0;
        for (int i = 0; i < n; i++) {
            int now = s[i] - '0';
            if ((i & 1) == 0) {
                if (now & 1) c1++;
                else c2++;
            }
            else {
                if (now & 1) c3++;
                else c4++;
            }
        }
        if (n & 1) {
            if (c1) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
        else {
            if (c4) {
                cout << 2 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        
    }



    return 0;
}