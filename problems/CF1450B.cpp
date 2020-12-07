/**
  * @Problem CF1450B.cpp.c
  * @Time 2020/12/6 22:22
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

struct node {
    int x, y;
}a[105];

int main () {
    int T;
    cin >> T;
    a:
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        for (int i = 1; i <= n; i++) {
            int ok = 1;
            for (int j = 1; j <= n; j++) {
                if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) > k) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << 1 << endl;
                goto a;
            }
        }
        cout << -1 << endl;


    }


    return 0;
}
