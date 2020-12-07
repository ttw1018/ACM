/**
  * @Problem CF1395E.cpp
  * @Time 2020/8/13 0:28
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const int maxn = 2e5 + 5;
vector<pair<int, int>> v[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

ll w[10][10];

int mod[3];

int n, m, k;


struct hash_number {
    int hs = 3;
    ll a[3];

    hash_number() {
        fill(a, a + hs, 0);
    }

    hash_number(ll x) {
        for (int i = 1; i < hs; i++) {
            a[i] = (x % mod[i] + mod[i]) % mod[i];
        }
    }

    hash_number operator+(hash_number x) {
        hash_number res;
        for (int i = 0; i < 3; i++) {
            res.a[i] = (a[i] + x.a[i]) % mod[i];
        }
        return res;
    }

    bool operator==(const hash_number &x) const {
        for (int i = 0; i < hs; i++) {
            if (a[i] != x.a[i]) return false;
        }
        return true;
    }

} val[maxn], c[10][10], s;


int dfs(int x, hash_number now) {
    if (x == k + 1) {
//        cout << now.a[0] << " " << s.a[0] << endl;
        return now == s;
    }

    int ans = 0;

    for (int i = 1; i <= x; i++) {
        ans += dfs(x + 1, now + c[x][i]);
    }
    return ans;
}


int main() {
    mod[0] = 998244353;
    mod[1] = 1e9 + 7;
    mod[2] = uniform_int_distribution<int>(1e8, 1e9)(mt_rand);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, to, w;
        cin >> u >> to >> w;
        v[u].push_back(make_pair(to, w));
    }

    uniform_int_distribution<ll> rg(1, 1e18);
    for (int i = 1; i <= n; i++) {
        val[i] = hash_number(rg(mt_rand));

    }

    for (int i = 1; i <= n; i++) s = s + val[i];

    for (int i = 1; i <= n; i++) {
        int d = v[i].size();
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j++) {
            c[d][j + 1] = c[d][j + 1] + val[v[i][j].first];
        }
    }

    cout << dfs(1, hash_number()) << endl;


    return 0;
}
