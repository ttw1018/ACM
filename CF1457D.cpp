#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7
//const int mod = 998244353;

const int maxn = 1e5 + 5;

ll a[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n >= 32 * 3) {
        cout << 1 << endl;
        return 0;
    }
    
    for (int i = 2; i <= n; i++) {
        a[i] ^= a[i - 1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= l; j++) {
                for (int k = i + j + 1; k + (l - j) <= n; k++) {
                    if ((a[i + j] ^ a[i - 1]) > (a[k - 1] ^ a[k + (l - j)])) {
                        // cout << l << " " << i << " " << j << " " << k << endl;
                        // cout << (a[i + j] ^ a[i - 1]) << " " << (a[k - 1] ^ a[k + (l - j)]) << endl;
                        cout << l << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << -1 << endl;

    return 0;
}