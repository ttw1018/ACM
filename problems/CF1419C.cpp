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
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        ll sum = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (a != x) {
                sum += a;
                cnt++;
            }
        }
        if (!cnt) {
            cout << 0 << endl;
        }
        else {
            if (cnt * x == sum || cnt != n) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
    }



    return 0;
}