#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2000005;

string s0;
string t;
int n, q;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


int nex[maxn];

int kmp(string s, string t) {

    nex[0] = -1;

    int j = -1, i = 0;
    while (i < s.length()) {
        if (j == -1 || s[i] == s[j]) {
            nex[++i] = ++j;
        } else {
            j = nex[j];
        }
    }

    i = 0, j = 0;
    int cnt = 0;
    while (i < t.length()) {
        if (j == -1 || t[i] == s[j]) {
            ++i;
            ++j;
        } else {
            j = nex[j];
        }
        if (j == s.length()) {
            cnt++;
            j = nex[j];
        }
    }
    return cnt;
}

ll cnt[30];

ll a[maxn][30];

ll init() {
    for (int i = 0; i <= n; i++) {
        if (i != 0) {
            for (int j = 0; j < 26; j++) {
                a[i][j] = a[i - 1][j] * 2 % mod;
            }
        }
        if (i < n)
            a[i][t[i] - 'a'] = (a[i][t[i] - 'a'] + 1) % mod;
    }
}

void solve() {
    int k;
    string s;
    cin >> k >> s;

    string now = s0;
    int flag = 0;
    int p;

    for (int _ = -1; _ < n; _++) {
        if (_ != -1)
            now = now + t[_] + now;
        if (now.length() >= s.length()) {
            flag = 1;
            p = _ + 1;
            break;
        }
    }
    if (!flag || p > k) {
        cout << 0 << endl;
        return;
    }

    ll ans = kmp(s, now) * qp(2, k - p) % mod;
    string now1 = now.substr(now.length() - s.length() + 1, s.length() - 1);
    now = now.substr(0, s.length() - 1);

    for (int i = 0; i < 6; i++) {
        cnt[i] = kmp(s, now1 + char(i + 'a') + now);
        ll x = 0;

        if (k >= 1 && p >= 1)
            x = (a[k - 1][i] - a[p - 1][i] + mod) % mod;
        else if (k >= 1) {
            x = a[k - 1][i];
        }
        cout << x << endl;
        ans = (ans + cnt[i] * x % mod % mod) % mod;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    cin >> s0;
    cin >> t;
    init();
    while (q--) {
        solve();
    }

    return 0;
}
