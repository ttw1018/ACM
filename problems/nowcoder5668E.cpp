/**
  * @Problem nowcoder5668E.cpp
  * @Time 2020/7/18 14:42
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;
ll A[maxn];

ll sum1[maxn], sum2[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A, A + n);
        ll ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans += A[i + 1] - A[i];
        }

        if (n % 4 == 0) {
            for (int i = 0; i < n; i += 4) {
                ans += A[i + 2] - A[i] + A[i + 3] - A[i + 1];
            }
            cout << ans << endl;
        } else {
            for (int i = 0; i < n - 2; i += 4) {
                sum1[i] = A[i + 2] - A[i] + A[i + 3] - A[i + 1];
                if (i - 4 >= 0) sum1[i] += sum1[i - 4];
            }

            for (int i = n - 1; i > 1; i -= 4) {
                sum2[i] = A[i] - A[i - 2] + A[i - 1] - A[i - 3];
                if (i + 4 <= n - 1) sum2[i] += sum2[i + 4];
            }
            ll res = 1e9;
            for (int i = 0; i + 5 <= n - 1; i += 4) {
                ll now = A[i + 2] - A[i] + A[i + 4] - A[i + 1] + A[i + 5] - A[i + 3];
                if (i - 4 >= 0) now += sum1[i - 4];
                if (i + 9 <= n - 1) now += sum2[i + 9];
                res = min(res, now);
            }
            cout << res + ans << endl;

        }
    }


    return 0;
}
