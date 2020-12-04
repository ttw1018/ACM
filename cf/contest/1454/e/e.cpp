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


int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<set<int>> e(n);
        vector<ll> val(n, 1);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].insert(y);
            e[y].insert(x);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (e[i].size() == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            int fa = *e[now].begin();
            val[fa] += val[now];
            val[now] = 0;
            e[fa].erase(now);
            e[now].clear();
            if (e[fa].size() == 1) {
                q.push(fa);
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += val[i] * (val[i] - 1) / 2;
            ans += val[i] * (n - val[i]);
        }
        cout << ans << endl;
    }

    return 0;
}