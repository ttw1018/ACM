/**
  * @Problem CF1393C.cpp
  * @Time 2020/8/7 22:31
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
        int ma = 0, cnt = 0;
        map<int, int> w;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            w[a]++;
            if (w[a] > ma) ma = w[a], cnt = 1;
            else if (w[a] == ma) cnt++;
        }
        if (ma == 1) {
            cout << n << endl;
            continue;;
        }
        int now = n - cnt * ma;
        int d = now / (ma - 1);
        cout << d + cnt - 1 << endl;

    }


    return 0;
}
