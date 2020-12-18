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
const int maxn = 1e7 + 5;


int prime[maxn], tot;

bool vis[maxn];

void findprime() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    ll q;
    cin >> q;

    findprime();
    ll now = q;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < tot && prime[i] <= now; i++) {
        if (now % prime[i] == 0) {
            cnt2++;
            while (now % prime[i] == 0) {
                now /= prime[i];
                cnt1++;
            }
        }
    }
    if (now > 1) cnt1++;

    if (cnt1 == 2) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }


    return 0;
}
