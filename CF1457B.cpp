#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n, k;

int solve(int x) {
    int cnt = 0;
    for (int i = 1; i <= n;) {
        if (a[i] != x) {
            i += k;
            cnt++;
        }
        else {
            i++;
        }
    }
    return cnt;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int ma = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        int ans = 1e9;
        for (int i = 1; i <= ma; i++) {
            ans = min(ans, solve(i));
        }
        cout << ans << endl;
        
    }
    


    return 0;
}