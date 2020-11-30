#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

// const int maxn = 2e5 + 5;
// const int mod = 1e9 + 7;

char s[105];

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        cin >> (s + 1);
        while (q--) {
            int l, r;
            cin >> l >> r;
            int flag = 0;
            for (int i = 1; i < l; i++) {
                if (s[i] == s[l]) {
                    flag = 1;
                    break;
                }
            }
            for (int i = r + 1; i <= n; i++) {
                if (s[i] == s[r]) {
                    flag = 1;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << endl;

        }

    }



    return 0;
}

