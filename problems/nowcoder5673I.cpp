/**  * @Problem nowcoder5673I.cpp
  * @Time 2020/8/3 12:39
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


const int maxn = 2e5 + 5;

int in[maxn];
int n;

struct edge {
    int from, to;

    edge(int a = 0, int b = 0) : from(a), to(b) {}
} e[maxn];

int head[maxn], tot;

void add(int x, int y) {
    e[++tot] = edge(head[x], y);
    head[x] = tot;
    e[++tot] = edge(head[y], x);
    head[y] = tot;
    in[x]++;
    in[y]++;
}

int a[maxn], b[maxn];
bool vis[maxn];
int len;

int topsort() {
    for (int i = 1; i <= len; i++) {
        vis[i] = 0;
    }
    queue<int> q;
    int ans = 0;
    for (int i = 1; i <= len; i++) {
        if (in[i] == 1) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (in[now] == 1) in[now] = 0;
        vis[now] = 1;
        int flag = 0;
        for (int i = head[now]; i; i = e[i].from) {
            int to = e[i].to;
            if (vis[to]) continue;
            if (--in[to] == 1) {
                q.push(to);
            }
            flag = 1;
        }
        if (flag) ans++;
    }
    for (int i = 1; i <= len; i++) {
        if (!vis[i]) ans++;
    }
    return ans;

}


int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            head[i] = 0;
            in[i] = 0;
        }
        tot = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i], &b[i]);
            v.push_back(a[i]);
            v.push_back(b[i]);
        }
        sort(v.begin(), v.end());
        len = unique(v.begin(), v.end()) - v.begin();
        for (int i = 0; i < n; i++) {
            int x = lower_bound(v.begin(), v.begin() + len, a[i]) - v.begin() + 1;
            int y = lower_bound(v.begin(), v.begin() + len, b[i]) - v.begin() + 1;
            add(x, y);
        }
        printf("Case #%d: %d\n", t, topsort());

    }


    return 0;
}


