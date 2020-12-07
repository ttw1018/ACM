/**
  * @Problem CF1395D.cpp
  * @Time 2020/8/12 23:34
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

vector<ll> v1, v2;

bool cmp(ll a, ll b) {
    return a > b;
}

const int maxn
ll sum1[maxn], sum2[maxn];


bool cmp(ll a, ll b) {
    return a > b;
}

ll a[maxn], b[maxn];

int main() {
    ll n, d;
    ll m;
    cin >> n >> d >> m;
    ll len1 = 0, len2 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x <= m) a[++len1] = x;
        else b[++len2] = x;
    }
    sort(a + 1, a + len1 + 1, cmp);
    sort(b + 1, b + len2 + 1, cmp);

    for (int i = 2; i <= len1; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 2; i <= len2; i++) {
        b[i] += b[i - 1];
    }
    ll ans = a[len1];
    // for (int i = 1; i <= len1; i++) cout << a[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= len2; i++)
    //   cout << b[i] << " ";
    // cout << endl;
    for (int i = 1; i <= len2; i++) {
        ll leave = n - (i - 1) * (d + 1) - 1;
        if (leave < 0) continue;
        ll res = b[i];
        res += a[min(len1, leave)];
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
}
