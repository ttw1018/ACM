/**
  * @Problem CF1418G.cpp
  * @Time 2020/9/18 12:36
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 9;
const int mod1 = 998244353;
const int maxn = 5e5 + 5;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

mt19937_64 g;

ll h[maxn];

map<int, vector<int>> q;
map<ll, ll> w, c;

decltype(g()) v[maxn];


int main() {
    int n;
    cin >> n;
    generate(v + 1, v + 1 + n, g);
    w[0] = 1;
    ll a;
    ll now = 0;
    ll ans = 0;
    int pos = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        q[a].push_back(i);
        if (q[a].size() > 3) {
            int val = q[a].front();
            while (pos < val) {
                w[h[pos++]]--;
            }
            q[a].erase(q[a].begin());
        }
        if (c[a] == 2) {
            now = now - v[a] * 2;
        } else {
            now = now + v[a];
        }
        h[i] = now;
        ans += w[now];
        w[now]++;
        c[a] = (c[a] + 1) % 3;
//        cout << "now: " << i << " " << now << endl;
    }

    cout << ans << endl;

    return 0;
}
