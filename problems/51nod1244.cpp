/**
  * @Problem 51nod1244.cpp
  * @Time 2020/8/7 10:26
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 6e6 + 5;

int u[maxn], prime[maxn];
bool vis[maxn];
int tot;
int s[maxn];

void init() {
    u[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            u[i] = -1;
        }
        for (int j = 0; j < tot && prime[j] * i < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
            u[i * prime[j]] = u[i] * (-1);
        }
    }
    s[1] = u[1];
    for (int i = 2; i < maxn; i++) s[i] = s[i - 1] + u[i];
}


unordered_map<ll, ll> w;


ll get(ll x) {
    if (x < maxn) return s[x];
    if (w[x]) return w[x];
    ll ans = 1;
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ans -= (r - l + 1) * get(x / l);
    }
    return w[x] = ans;
}

int main() {
    init();
    ll a, b;
    cin >> a >> b;
    cout << get(b) - get(a - 1) << endl;


    return 0;
}
