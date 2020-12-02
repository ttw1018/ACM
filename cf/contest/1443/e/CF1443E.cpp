#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

ll c[20];
ll a[maxn];

int len;

void get(ll x) {
    vector<int> v;
    for (int i = 1; i <= len; i++) {
        v.push_back(i);
    }
    for(int i = 1; i <= len; i++) {
        ll now = x / c[len - i];
        a[i] = v[now];
        x %= c[len - i];
        v.erase(v.begin() + now);
    }
    // for (int i = 1; i <= 4; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
}



int main () {
    c[0] = 1;

    for (int i = 1; i <= 15; i++) {
        c[i] = c[i - 1] * i;
    }

    // len = 4;
    //
    // for (int i = 0; i < 24; i++)
    //     get(i);
    //

    int n, q;
    cin >> n >> q;
    len = min(n, 15);
    for (int i = 1; i <= len; i++) {
        a[i] = i;
    }

    ll x = 0;


    while (q--) {
        int ope;
        cin >> ope;
        if (ope == 1) {
            int l, r;
            cin >> l >> r;
            ll ans = 0;
            if (r > n - len) {
                int lll = max(l, n - len + 1);
                
                ans = (n - len) * (r - lll + 1);
                for (int i = lll - (n - len); i <= r - (n - len); i++) {
                    ans += a[i];
                }
                if (l <= n - len) {
                    ans += ll(1) * (l + n - len) * (n - len - l + 1) / 2;
                }
                cout << ans << endl;
            }
            else {
                cout << ll(1) * (r - l + 1) * (l + r) / 2 << endl;
            }
        }
        else {
            ll a;
            cin >> a;
            x += a;
            
            get(x);
        }

    }

    return 0;
}

