/**
  * @Problem CF1394B.cpp
  * @Time 2020/8/12 22:34
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;


int vis[105][105];

int main() {

    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;

    cout << x << " " << y << endl;
    vis[x][y] = 1;

    int k;
    int ed;
    for (k = 1; k <= m; k++) {
        if (!vis[x][k]) {
            cout << x << " " << k << endl;
            vis[x][k] = 1;
            ed = k;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i][ed]) {
            cout << i << " " << ed << endl;
            vis[i][ed] = 1;
            for (k = 1; k <= m; k++) {
                if (!vis[i][k]) {
                    cout << i << " " << k << endl;
                    ed = k;
                }
            }
        }
    }


    return 0;
}
