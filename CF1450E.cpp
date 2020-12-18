//
// Created by ttw on 2020/12/9.
//


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;

int e[205][205];

int dis[205][205];


int main () {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 1e9;
        }
        dis[i][i] = 0;
    }
    int u[2005], v[2005];

    for (int i = 1; i <= m; i++) {
        int a, b, sta;
        cin >> a >> b >> sta;
        u[i] = a;
        v[i] = b;
        if (sta) {
            e[a][b] = 1;
            e[b][a] = -1;
            dis[a][b] = 1;
            dis[b][a] = -1;
        }
        else {
            e[a][b] = e[b][a] = 1;
            dis[a][b] = dis[b][a] = 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++)  {
//            cout << dis[i][j] << " ";
//        }
//        cout << endl;
//    }

    pair<int, int> now(0,-1);

    for (int i = 1; i <= n; i++) {
        if (dis[i][i] < 0) {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            now = max(now, {dis[i][j], i});
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dis[now.second][u[i]] == dis[now.second][v[i]])  {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << "\n" << now.first << endl;

    for (int i = 1; i <= n; i++) {
        cout << dis[now.second][i] << " ";
    }
    cout << "\n";


    return 0;
}
