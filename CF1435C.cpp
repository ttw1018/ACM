#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;


int b[10];
int a[maxn];

int v[maxn][10];

int p[maxn];

bool cmp(int a, int b) {
    return a > b;
}

int c[6];
int d[maxn];

int main() {
    for (int i = 0; i < 6; i++) cin >> b[i];
    sort(b, b + 6);
    int all = 0;
    c[all++] = b[0];
    for (int i = 1; i < 6; i++) {
        if (b[i] != c[all - 1]) c[all++] = b[i];
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    d[1] = a[1];
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] != d[cnt]) {
            d[++cnt] = a[i];
        }
    }
    n = cnt;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < all; j++) {
            v[i][j] = d[i] - c[all - j - 1];
//            cout << v[i][j] << " ";
        }
//        cout << endl;
    }


    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++) {
        s.insert(make_pair(v[i][0], i));
        p[i] = 1;
    }
    int ans = s.rbegin()->first - s.begin()->first;
    if (all == 1) {
        cout << ans << endl;
        return 0;
    }
    while (true) {
        int ed = 0;
        int id = s.begin()->second;
        if (p[id] == all) break;
        s.erase(s.begin());
        s.insert(make_pair(v[id][p[id]++], id));
        ans = min(ans, s.rbegin()->first - s.begin()->first);
        if (ed) break;
    }
    cout << ans << endl;


    return 0;
}