/**
  * @Problem nowcoder6878A.cpp
  * @Time 2020/8/4 9:09
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int a;
        map<int, int> w;
        while (cin >> a && a) {
            w[a]++;
        }
        int cnt = 0;

        for (auto i : w) {
            if (i.second & 1) {
                cnt++;
            }
        }
        if (cnt & 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }


    return 0;
}
