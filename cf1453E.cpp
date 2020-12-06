//
// Created by ttw on 2020/12/5.
//

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

const int maxn = 2e5 + 5;

vector<int> e[maxn];
int dep[maxn];
int ma[maxn];
int mi[maxn];
int val[maxn];
int ans = 0;

void dfs (int now, int fa) {
    val[now] = 0;
    vector<int> v;
    for (auto i : e[now]) {
        if (i != fa) {
            dfs(i, now);
            v.push_back(val[i] + 1);
        }
    }
    sort(v.begin(), v.end());
    if (v.size() == 1) {
        val[now] = v[0];
        ans = max(ans, val[now]);
    }
    else if (v.size() > 1 && now != 1) {
        val[now] = v[0];
        ans = max(ans, v[v.size() - 1] + 1);
    }
    else if (v.size() > 1 && now == 1) {
        ans = max(ans, max(v[v.size() - 2] + 1, v[v.size() - 1]));
    }
//    cout << now << "  " << val[now] << " " << ans << endl;
}


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;

    }
    return 0;
}