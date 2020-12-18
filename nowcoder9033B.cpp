//
// Created by ttw on 2020/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;

int a[maxn];

int fa[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void add(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (x > y) swap(x, y);
        fa[y] = x;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a == 0 && i > 1) {
            add(i, i - 1);
        }
        if (a == 1 && i < n) {
            add(i, i + 1);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) cnt++;
    }
    cout << cnt << endl;


    return 0;
}