/**
  * @Problem nowcoder5675A.cpp
  * @Time 2020/8/10 12:43
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e6 + 5;

bool vis[maxn];
int a[maxn], b[maxn];

int main() {
    int T;
    cin >> T;
    a[1] = 1;
    b[1] = 1;
    while (T--) {
        int n;
        cin >> n;
        if (n == 3) {
            cout << "1 2\n";
            continue;
        }
        for (int i = 1; i < n; i++) {
            vis[i] = 1;
        }
        vis[1] = 1;
        int flag = 1;
        for (int i = 2; i < n; i++) {
            a[i] = a[i - 1] * 2 % n;
            if (vis[a[i]]) {
                a[i] = a[i - 1] * 3 % mod;
                if (vis[a[i]]) {
                    flag = 0;
                    break;
                }
                vis[a[i]] = 1;
            }
            vis[a[i]] = 0;
        }

        if (!flag) cout << -1 << endl;
        else {
            for (int i = 1; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}
