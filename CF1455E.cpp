#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 1e5 + 5;

ll get(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll solve(vector<pair<ll, ll>> v, ll a1, ll a2, ll b1, ll b2)
{
    pair<ll, ll> p1 = { a1, b1 }, p2 = { a1, b2 }, p3 = { a2, b1 }, p4 = { a2, b2 };

    ll ans = 1e18;
    for (int i1 = 0; i1 < 4; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
            for (int i3 = 0; i3 < 4; i3++) {
                for (int i4 = 0; i4 < 4; i4++) {
                    int vis[4];
                    memset(vis, 0, sizeof(vis));
                    vis[i1] = 1;
                    vis[i2] = 1;
                    vis[i3] = 1;
                    vis[i4] = 1;
                    int cnt = 0;
                    for (int i = 0; i < 4; i++) {
                        cnt += vis[i];
                    }
                    if (cnt == 4) {
                        ll now = get(v[i1], p1) + get(v[i2], p2) + get(v[i3], p3) + get(v[i4], p4);
                        ans = min(ans, now);
                    }
                }
            }
        }
    }

    return ans + 2 * abs(a2 - a1 - (b2 - b1));
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        vector<pair<ll, ll>> v(4);
        set<int> v1, v2;
        for (int i = 0; i < 4; i++) {
            cin >> v[i].first >> v[i].second;
            v1.insert(v[i].first);
            v2.insert(v[i].second);
        }

        ll ans = 1e18;
        for (auto a1 : v1) {
            for (auto a2 : v1) {
                for (auto b1 : v2) {
                    ans = min(ans, solve(v, a1, a2, b1, b1 + a2 - a1));
                }
            }
        }
        for (auto a1: v1) {
            for (auto b1 : v2) {
                for (auto b2 : v2) {
                    ans = min(ans, solve(v, a1, a1 + b2 - b1, b1, b2));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}