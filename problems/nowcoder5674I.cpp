/**
  * @Problem nowcoder5674I.cpp
  * @Time 2020/8/8 12:59
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

int a[maxn], now[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);

        int k;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                k = a[i];
                a[1] = a[i + 1];
                if (a[0] == 0)
                    a[i + 1] = 0;
                if (i != 1)
                    a[i] = 0;
                break;
            }
        }
//        for (int i = 1; i < n; i++) {
//            cout << a[i];
//        }
//        cout << endl;

        int mod = 0;
        for (int i = n - 1; i >= 0; i--) {
            a[i] = a[i] * k + mod;
            mod = a[i] / 10;
            a[i] = a[i] % 10;
        }
        if (a[0] > 0) printf("%d", a[0]);
        for (int i = 1; i < n; i++) {
            printf("%d", a[i]);
        }
        puts("");
    }


    return 0;
}
