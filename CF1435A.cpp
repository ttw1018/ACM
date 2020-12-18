#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

int a[maxn];


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n & 1) {
            for (int i = -100; i <= 100; i++) {
                if (i == 0) continue;
                for (int j = -100; j <= 100; j++) {
                    if (j == 0) continue;
                    int now = i * a[1] + j * a[2];
                    if (now == 0) continue;
                    if (abs(now) % abs(a[3]) == 0) {
                        cout << i << " " << j << " " << -now / a[3] << " ";
                        goto a;
                    }
                }
            }
            a:
            for (int i = 4; i <= n; i += 2) {
                cout << -a[i + 1] << " " << a[i] << " ";
            }

        } else {
            for (int i = 1; i <= n; i += 2) {
                cout << -a[i + 1] << " " << a[i] << " ";
            }
        }
        cout << endl;


    }

    return 0;
}