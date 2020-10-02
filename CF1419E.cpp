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

int prime[maxn];
int tot = 0;
bool vis[maxn];

void init () {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int a[500];
int gcd (int x, int y) {
    return y ? gcd(y, x % y) : x;
}
int main () {
    int t;
    cin >> t;
    init();
    while (t--) {
        ll n;
        cin >> n;
        int p = 0;
        a[++p] = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (n / i != i) {
                    a[++p] = i;
                    a[++p] = n / i;
                }
                else {
                    a[++p] = i;
                }
            }
        }
        
        int now = n;
        int base[50], mi[50];

        int c = 0;
        vector<int>  v[50];
        for (int i = 0; i < tot && prime[i] <= now; i++) {
            if (now % prime[i] == 0) {
                int tmp = 1;
                while (now % prime[i] == 0) {
                    tmp *= prime[i];
                    now /= prime[i];
                }
                base[++c] = prime[i];
            }
        }

        if (now > 1) {
            base[++c] = now;
        }

        if (c == 1) {
            for (int i = 1; i <= p; i++) {
                cout << a[i] << " ";
            }
            cout << endl << 0 << endl;
            continue;
        }

        if (p == 3 && c == 2) {
            for (int i = 1; i <= p; i++) {
                cout << a[i] << " ";
            }
            cout << endl << 1 << endl;
            continue;
        }

        map<int, int> w;
        v[1].push_back(base[1] * base[c]);
        v[1].push_back(base[1]);
        w[base[1]] = 1;
        w[base[1] * base[c]] = 1;
        if (c > 2) {
            for (int i = 2; i <= c; i++) {
                v[i].push_back(base[i] * base[i - 1]);
                v[i].push_back(base[i]);
                w[base[i]] = 1;
                w[base[i] * base[i - 1]] = 1;
            }
        }
        else {
            if (n % (ll(base[1]) * base[1] * base[2]) == 0) {
                v[2].push_back(base[1] * base[1] * base[2]);
                w[base[1] * base[1] * base[2]] = 1;
            } 
            else {
                v[2].push_back(base[1] * base[2] * base[2]);
                w[base[1] * base[2] * base[2]] = 1;
            }
            v[2].push_back(base[2]);
            w[base[2]] = 1;
        }
        
        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= c; j++) {
                if (!w[a[i]] && a[i] % base[j] == 0) {
                    v[j].push_back(a[i]);
                    break;
                }
            }
        }
        for (int i = 1; i <= c; i++) {
            for (auto j : v[i]) {
                cout << j << " ";
            }
        }
        cout << endl;
        cout << 0 << endl;
        
    }



    return 0;
}