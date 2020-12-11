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

void dfs(int x, int fa)
{
    vector<int> v;
    for (auto to : e[x]) {
        if (to != fa) {
            dfs(to, x);
            v.push_back(val[to] + 1);
        }
    }
    if (v.size() == 0)
        val[x] = 1;
    else if (v.size() == 1) {
        val[x] = v[0];
    }
    else {
        val[x] = v[v.size() - 2] + 1;
    }
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
            dep[i] = ma[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(1, 0);
        cout << val[1] << endl;
    }
    return 0;
}