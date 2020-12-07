/**
  * @Problem 51nod1259.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/11 17:31
*/

// 正五边形数， 整数划分

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 5e4 + 5;
ll ans[maxn];
ll temp[maxn];

void MOD(ll &x) {
    x = (x % mod + mod) % mod;
}

void init() {
    int t = 1000;
    for (int i = -1000; i <= 1000; i++) {
        temp[i + t] = i * (3 * i - 1) / 2;
    }


    ans[0] = 1;
    for (int i = 1; i <= maxn; i++) {
        for (int j = 1; j <= i; j++) {
            if (temp[t + j] <= i) {
                if (j & 1) ans[i] += ans[i - temp[j + t]];
                else ans[i] -= ans[i - temp[j + t]];
                MOD(ans[i]);
            } else break;
            if (temp[t - j] <= i) {
                if (j & 1) ans[i] += ans[i - temp[t - j]];
                else ans[i] -= ans[i - temp[t - j]];
                MOD(ans[i]);
            } else break;
        }
//        cout << ans[i] << endl;
    }
}

int main() {
    init();
    int n;
    cin >> n;
    cout << ans[n] << endl;


    return 0;
}
