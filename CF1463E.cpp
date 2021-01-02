//
// Created by ttw on 2020/12/18.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;

vector<int> v[maxn];

int pre[maxn];
int fa[maxn];
int son[maxn];
int nex[maxn];
int in[maxn];

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    for (int i = 1; i <= n; i++) {
        nex[i] = fa[i] = son[i] = i;
    }

    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        nex[a] = b;
        son[a] = b;
        fa[b] = a;
        v[a].push_back(b);
        in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        int now = i;
        int cnt = 0;
        while (son[now] != now) {
            now = son[now];
            cnt++;
            if (cnt > n) {
                cout << 0 << endl;
                return 0;
            }
        }
        son[i] = now;
        now = i;
        cnt = 0;
        while (fa[now] != now) {
            now = fa[now];
            cnt++;
            if (cnt > n) {
                cout << 0 << endl;
                return 0;
            }
        }
        fa[i] = now;
    }

    for (int i = 1; i <= n; i++) {
        if (fa[i] == fa[pre[i]]) {
            v[pre[i]].push_back(i);
            in[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int now = q.front();
        cnt++;
        q.pop();
        for (auto to : v[now]) {
            if (--in[to] == 0) {
                q.push(to);
            }
        }
    }
    if (cnt != n) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        v[i].clear();
        in[i] = 0;
    }


    for (int i = 1; i <= n; i++) {
        if (fa[pre[i]] == fa[i]) continue;
        v[fa[pre[i]]].push_back(fa[i]);
        in[fa[i]]++;
    }

    for (auto to : v[0]) {
        if (in[to] == 1)
            q.push(to);
    }

    vector<int> ans;
    while (!q.empty()) {
        int now = q.front();
        ans.push_back(now);
        q.pop();
        for (auto to : v[now]) {
            if (--in[to] == 0) {
                q.push(to);
            }
        }
    }

    vector<int> res;


    for (auto i : ans)  {
//        cout << i << " ";
        res.push_back(i);
        while (nex[i] != i) {
            i = nex[i];
            res.push_back(i);
        }
    }
//    cout << endl;

    if (res.size() != n) {
        cout << 0 << endl;
        return 0;
    }

    for (auto i : res)  {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
