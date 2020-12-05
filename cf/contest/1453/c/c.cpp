#include <algorithm>
#include <climits>
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
//const int mod = 998244353;

const int maxn = 1e5 + 5;

int a[2005][2005];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int l[10][2005], r[10][2005];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        
        int lma[10], lmi[10], cma[10], cmi[10];
        for (int i = 0; i < 10; i++) {
            lma[i] = cma[i] = 0;
            lmi[i] = cmi[i] = n + 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char c;
                cin >> c;
                a[i][j] = c - '0';
                cnt[a[i][j]]++;
                int k = a[i][j];
                lmi[k] = min(i, lmi[k]);
                lma[k] = max(i, lma[k]);
                cmi[k] = min(j, cmi[k]);
                cma[k] = max(j, cma[k]);
            }
        }
        
        for (int k = 0; k <= 9; k++) {
            if (cnt[k] <= 1) {
                cout << 0 << " ";
                continue;
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int l = -1, r = -1;
                for (int j = 1; j <= n; j++) {
                    if (a[i][j] == k) {
                        if (l == -1) {
                            l = r = j;
                        }
                        else r = j;
                    }
                }
                if (l == -1)continue;
                
                int llmi = lmi[k] == n + 1 ? i : lmi[k];
                int llma = lma[k] == 0 ? i : lma[k];
            
                int maxl = max(abs(llmi - i), abs(llma - i));
                
                ans = max(ans, (r - l) * max(i - 1, n - i));
                ans = max(ans, maxl * max(r - 1, n - l));
                
            }
            
            for (int j = 1; j <= n; j++) {
                int l = -1, r = -1;
                for (int i = 1; i <= n; i++) {
                    if (a[i][j] == k) {
                        if (l == -1) l = r = i;
                        else r = i;
                    }
                }
                if (l == -1) continue;
                
                int ccmi = cmi[k] == n + 1 ? j : cmi[k];
                int ccma = cma[k] == 0 ? j : cma[k];
                
                int maxl = max(abs(ccmi - j), abs(ccma - j));
                ans = max(ans, (r - l) * max(j - 1, n - j));
                ans = max(ans, maxl * max(r - 1, n - l));
            }
            cout << ans << " ";
        }
        cout << endl;
        
        
        
        
    }
    
    
    return 0;
}