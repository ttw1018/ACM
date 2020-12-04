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
const int mod = 998244353;

const int maxn = 2e5 + 5;

int a[maxn];
int b[maxn];
int pos[maxn];
int l[maxn], r[maxn];
int id[maxn];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        for (int i = 0; i <= n + 1; i++) {
            l[i] = r[i] = pos[i] = id[i] = 0;
        }
        
        
        for (int i = 1; i <= n; i++) cin >> a[i], id[a[i]] = i;
        for (int i = 1; i <= k; i++) cin >> b[i], pos[b[i]] = i;

        for (int i = 1; i <= n; i++) {
            l[i] = a[i - 1];
            r[i] = a[i + 1];
        }
        l[1] = n + 1;
        r[n] = n + 1;
        pos[n + 1] = k + 1;
        
        ll ans = 1;
        for (int i = 1; i <= k; i++) {
            int p = id[b[i]];
            if (pos[l[p]] < i && pos[r[p]] < i) {
                ans = ans * 2 % mod;
            }
            else if (pos[l[p]] < i || pos[r[p]] < i) {
                continue;
            }
            else {
                ans = 0;
                break;
            }
        }
        cout << ans << endl;

    }

    return 0;
}
