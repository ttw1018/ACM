/**
  * @Problem nowcoder7023A.cpp
  * @Time 2020/8/12 9:44
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
int prime[maxn], vis[maxn];
int tot;
vector<int> v[maxn];


void init() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            v[i].push_back(i);
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            v[i * prime[j]].push_back(prime[j]);
            for (auto k : v[i]) {
                v[i * prime[j]].push_back(k);
            }
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int t[maxn];

int lowbit(int x) {
    return x & (-x);
}


void add(int k) {
    while (k) {
        t[k]++;
        k -= lowbit(k);
    }
}

int ma;

int query(int x) {
    int ans = 0;
    while (x <= ma) {
        ans += t[x];
        x += lowbit(x);
    }
    return ans;
}

int cnt1[maxn], cnt2[maxn];


int a[maxn], b[maxn];

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        ma = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ma = max(a[i], ma);
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            ma = max(b[i], ma);
        }

        for (int i = 1; i <= ma; i++) {
            t[i] = cnt1[i] = cnt2[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            add(a[i]);
        }


        for (int i = 1; i <= ma; i++) {
            int x = query(i);
            for (auto j : v[i]) {
                cnt1[j] += x;
            }
        }

        for (int i = 1; i <= ma; i++) {
            t[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            add(b[i]);
        }

        for (int i = 1; i <= ma; i++) {
            int x = query(i);
            for (auto j : v[i]) {
                cnt2[j] += x;
            }
        }

        bool ok = true;
        for (int i = 2; i <= ma; i++) {
            if (cnt1[i] != cnt2[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "equal" << endl;
        } else {
            cout << "unequal" << endl;
        }

    }


    return 0;
}
