/**
  * @Problem hduday4_1002.cpp
  * @Time 2020/7/30 12:35
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


ll A[1005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a, d;
            cin >> a >> d;
            A[i] = ((100 - 1) / a) * d;
        }
        sort(A + 1, A + 1 + n);
        int cnt = 1;
        for (int i = 2; i <= n; i++) {
            if (A[i] == A[1]) {
                cnt++;
            }
        }

        double ans = 1 - 0.5 * cnt / n;
        cout << fixed << setprecision(10) << ans << endl;


    }


    return 0;
}
