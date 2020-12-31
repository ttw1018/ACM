/**
  * @Problem D.cpp.c
  * @Time 2020/12/31 21:36
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;


ll val[50];

int main() {
    val[0] = val[1] = 1;
    for (int i = 2; i <= 12; i++) {
        val[i] = i * val[i - 1];
    }
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    for (int x = 0; x <= a; x++) {
        for (int y = 0; y <= b; y++) {
            for (int z = 0; z <= c; z++) {
                if (x + y + z == 0) continue;
                if (x == 0 && y == 0) ans++;
                else if (x == 0 && z == 0) ans++;
                else if (y == 0 && z == 0) ans++;
                else if (x + y + z <= 2) {
                    ans++;
                } else if (x != 0 && y != 0 && z != 0) {
                    ans += val[x + y + z - 1] / val[x] / val[y] / val[z];
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}
