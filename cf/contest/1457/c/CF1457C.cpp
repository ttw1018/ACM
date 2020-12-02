#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int a[maxn];
ll dp[maxn][2];

int n, p, k;
ll cnt[maxn];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            a[i + 1] = s[i] - '0';
        }
        ll x, y;
        cin >> x >> y;
        memset(cnt, 0, sizeof(cnt));
        for (int i = p; i <= n; i++) {
            cnt[(i - p) % k] += !a[i];
        }
        ll ans = 1e18;
        for (int i = 0; n - i >= p; i++) {
            ans = min(ans, i * y + x * cnt[i % k]);
            if (i + p <= n && !a[i + p]) cnt[i % k]--;
        }

        cout << ans << endl;
    }

    return 0;
}