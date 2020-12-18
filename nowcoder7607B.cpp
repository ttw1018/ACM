#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

int c[maxn][2];
int cnt = 0;

void add(int x) {
    int now = 0;
    while (x) {
        int v = x & 1;
        if (!c[now][v]) {
            c[now][v] = ++cnt;
        }
        now = c[now][v];
        x >>= 1;
    }
}

bool que(int x, int now) {
    if (x == 1) return c[now][1];
    int v = x & 1;
    if (v) {
        if (!c[now][v]) {
            return false;
        }
        return que(x >> 1, c[now][1]);
    } else {
        bool yes = 0;
        if (c[now][v]) yes |= que(x >> 1, c[now][v]);
        if (c[now][1]) yes |= que(x >> 1, c[now][1]);
        if (!c[now][0] && !c[now][1]) return false;
        return yes;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << (que(x, 0) ? "yes" : "no") << endl;
    }

    return 0;
}