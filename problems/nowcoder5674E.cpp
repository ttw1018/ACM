/**
  * @Problem nowcoder5674E.cpp
  * @Time 2020/8/8 13:58
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

const int maxn = 1e5 + 5;
int prime[maxn], tot;
bool vis[maxn];

void init() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot && prime[j] * i < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll get(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    init();
    ll a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    ll ans = 1;

    vector<pair<ll, pair<ll, ll>>> v;

    for (int i = 0; i < tot && prime[i] <= x; i++) {
        if (x % prime[i] == 0) {
            int cnt1 = 0, cnt2 = 0;
            while (x % prime[i] == 0) {
                cnt1++;
                x /= prime[i];
            }
            while (y % prime[i] == 0) {
                cnt2++;
                y /= prime[i];
            }
            if (cnt2) {
                v.push_back(make_pair(prime[i], make_pair(cnt1, cnt2)));
            }
        }
    }

    if (x != 1) {
        int cnt = 0;
        while (y % x == 0) {
            cnt++;
            y /= x;
        }
        if (cnt) {
            v.push_back(make_pair(x, make_pair(1, cnt)));
        }
    }

    for (int i = 0; i < v.size(); i++) {
        ll base = v[i].first;
        ll c1 = v[i].second.first, c2 = v[i].second.second;
        ll all = 0;
//        cout << base << " " << c1 << " " << c2 << endl;
        for (ll j = a; j <= b; j++) {
            ll s = j * c1 / c2;
            if (s < c) {
                all += j * c1 * (d - c + 1);
            } else if (s > d) {
                all += c2 * get(c, d);
            } else {
                all += c2 * get(c, s);
                all += j * c1 * (d - s);
            }
            all %= (mod - 1);
        }
        ans = ans * qp(base, all) % mod;
    }
    cout << ans << endl;
    return 0;
}


