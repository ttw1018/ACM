/**
  * @Problem nowcoder5674B.cpp
  * @Time 2020/8/8 16:24
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

vector<pair<int, ll>> v[maxn];

ll val[maxn];


bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first >= 0) {
        if (b.first < 0) return 1;
        return a.second > b.second;
    } else {
        if (b.first >= 0) return 0;
        return a.first + b.second > b.first + a.second;
    }
}

pair<ll, ll> dfs(int now, int fa) {
    vector<pair<ll, ll>> stor;
    for (auto i : v[now]) {
        if (i.first != fa) {
            pair<ll, ll> p = dfs(i.first, now);
            p.first -= 2 * i.second;
            p.second -= i.second;
            p.second = min(p.first, p.second);
            stor.push_back(p);
        }
    }

    pair<ll, ll> ans;
    ans.first = val[now];
    ans.second = 0;

    sort(stor.begin(), stor.end(), cmp);

    for (auto i : stor) {
        ans.second = min(ans.second, ans.first + i.second);
        ans.first += i.first;
    }
    return ans;


}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) v[i].clear();

        for (int i = 1; i <= n; i++) cin >> val[i];

        for (int i = 1; i < n; i++) {
            int to, from;
            ll val;
            cin >> from >> to;
            cin >> val;
            v[from].push_back(make_pair(to, val));
            v[to].push_back(make_pair(from, val));
        }
        cout << -dfs(1, 1).second << endl;

    }

    return 0;
}
