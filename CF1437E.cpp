#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

int a[maxn], b[maxn];

int t[maxn];

int lowbit(int x) { return x & -x; }

int len;

int que(int x) {
    int ans = 0;
    while (x) {
        ans = max(ans, t[x]);
        x -= lowbit(x);
    }
    return ans;
}

void upd(int x, int v) {
    while (x <= len) {
        t[x] = max(t[x], v);
        x += lowbit(x);
    }
}


int get(vector<int> v) {

    vector<int> all = v;

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    len = v.size();
    int ans = 0;
    for (int i = 0; i < all.size(); i++) {
        int now = all[i];
        int id = lower_bound(v.begin(), v.end(), now) - v.begin() + 1;
        int ma = que(id);
        ans = max(ans, ma + 1);
        upd(id, ma + 1);
    }
    for (int i = 1; i <= len; i++) t[i] = 0;
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 2; i <= m; i++) {
        if (a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1]) {
            cout << "-1" << endl;
            return 0;
        }
    }

    b[0] = 0;
    b[m + 1] = n + 1;
    a[0] = -1e9;

    a[n + 1] = 2e9;

    int ans = 0;
    for (int j = 1; j <= m + 1; j++) {
        vector<int> v;
        for (int i = b[j - 1] + 1; i < b[j]; i++) {
            if (a[i] - a[b[j - 1]] < i - b[j - 1] || a[b[j]] - a[i] < b[j] - i) {
                continue;
            }
            v.push_back(a[i] - i);
        }
        if (v.size()) {
            ans += b[j] - b[j - 1] - 1 - get(v);
        } else {
            ans += b[j] - b[j - 1] - 1;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}