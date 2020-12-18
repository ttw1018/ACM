//
// Created by ttw on 2020/12/18.
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
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;


bool vis[10000];

int main () {
    ll n, x, y;
    cin >> n >> x >> y;

    for (int i = 1; i <= 5000; i++) {
        if (!vis[i]) {
            vis[i + x] = 1;
            vis[i + y] = 1;
        }
    }

    int cyc = -1;

    for (int k = 300; k <= 2500; k++) {
        int flag = 1;
        for (int i = 1; i <= k; i++) {
            if (vis[i] != vis[i + k]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cyc = k;
            break;
        }
    }
    cout << cyc << endl;

    int sig = 0;
    for (int i = 1; i <= cyc; i++) {
        if (!vis[i]) sig++;
    }

    int ans = n / cyc * sig;

    n %= cyc;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) ans++;
    }
    cout << ans << endl;

    cout << 1014 % 117 << endl;


    return 0;
}
