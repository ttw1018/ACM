/**
 * @Problem CF1442C.cpp.c
 * @Time 2020/12/14 19:10
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 998244353;
const int maxn = 2e5 + 5;

int n, m;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

vector<int> v1[maxn], v2[maxn];

struct node {
    int now, dep, cnt;

    node(int a = 0, int b = 0, int c = 0) : now(a), dep(b), cnt(c) {}

    bool operator<(node a) const {
        if (cnt == a.cnt)
            return dep < a.dep;
        if (dep == a.dep)
            return cnt < a.cnt;
        if (cnt > 25 && a.cnt > 25)
            return cnt < a.cnt;
        if (cnt > 25)
            return false;
        if (a.cnt > 25)
            return true;
        int now1 = dep + (1 << cnt);
        int now2 = a.dep + (1 << a.cnt);
        return now1 < now2;
    }

    bool operator>(node a) const {
        if (dep == a.dep)
            return cnt > a.cnt;
        if (cnt == a.cnt)
            return dep > a.dep;
        if (cnt > 25 && a.cnt > 25)
            return cnt > a.cnt;
        if (cnt > 25)
            return true;
        if (a.cnt > 25)
            return false;
        int now1 = dep + (1 << cnt);
        int now2 = a.dep + (1 << a.cnt);
        return now1 > now2;
    }
};

node dis1[maxn][26], dis2[maxn][26];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }

    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node(1, 0, 0));

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 25; j++) {
            dis1[i][j].dep = -1;
            dis2[i][j].dep = -1;
        }
    }
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (now.now == n) {
            cout << (now.dep + qp(2, now.cnt) - 1) % mod << endl;
            return 0;
        }
        for (auto to : v1[now.now]) {
            node tmp = now;
            tmp.now = to;
            tmp.dep++;
            if (tmp.cnt & 1) {
                tmp.cnt++;
                if (dis1[to][min(25, tmp.cnt)].dep == -1 || tmp < dis1[to][min(25, tmp.cnt)]) {
                    q.push(tmp);
                    dis1[to][min(25, tmp.cnt)] = tmp;
                }
            } else {
                if (dis1[to][min(25, tmp.cnt)].dep == -1 || tmp < dis1[to][min(25, tmp.cnt)]) {
                    q.push(tmp);
                    dis1[to][min(25, tmp.cnt)] = tmp;
                }
            }
        }
        for (auto to : v2[now.now]) {
            node tmp = now;
            tmp.dep++;
            tmp.now = to;
            if ((tmp.cnt & 1) == 0) {
                tmp.cnt++;
                if (dis2[to][min(25, tmp.cnt)].dep == -1 || tmp < dis2[to][min(25, tmp.cnt)]) {
                    q.push(tmp);
                    dis2[to][min(25, tmp.cnt)] = tmp;
                }
            } else {
                if (dis2[to][min(25, tmp.cnt)].dep == -1 || tmp < dis2[to][min(25, tmp.cnt)]) {
                    q.push(tmp);
                    dis2[to][min(25, tmp.cnt)] = tmp;
                }
            }
        }
    }

    return 0;
}