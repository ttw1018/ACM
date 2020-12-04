#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 2e5 + 5;

int a[maxn];

struct node {
    int l, r, v;
} t[maxn * 4];

void build(int k, int l, int r)
{
    t[k].l = l;
    t[k].r = r;
    if (l == r) {
        t[k].v = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
    t[k].v = min(t[k * 2].v, t[k * 2 + 1].v);
}

int que(int k, int l, int r)
{
    if (t[k].l >= l && t[k].r <= r) {
        return t[k].v;
    }
    int m = (t[k].l + t[k].r) >> 1;
    int now = 1e9;
    if (l <= m)
        now = min(now, que(k * 2, l, r));
    if (r > m)
        now = min(now, que(k * 2 + 1, l, r));
    return now;
}

int main()
{
    int T;
    cin >> T;
a:
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int vl = a[1], vr = a[n];
        int l = 1, r = n;
        build(1, 1, n);
        map<int, vector<int>> w1, w2;
        for (int i = 1; i <= n; i++) {
            vl = max(vl, a[i]);
            while(i < n && a[i + 1] < vl) {
                i++;
            }
            w1[vl].push_back(i);
        }
        for (int i = n; i >= 1; i--) {
            vr = max(vr, a[i]);
            while(r > 1 && a[r - 1] < vr) {
                r--;
            }
            w2[vr].push_back(i);
        }
        
        for (auto i : w1) {
            for (auto j : i.second) {
                for (int z = w2[i.first].size() - 1; z >= 0; z--) {
                    int k = w2[i.first][z];
                    if (k - j > 1) {
                        int now = que(1, j + 1, k - 1);
                        if (now == i.first) {
                            cout << "YES" << endl;
                            cout << j << " " << k - j - 1 << " " << n - k + 1 << endl;
                            goto a;
                        }
                        else if (now < i.first) break;
                    }
                }
            }
        }
        cout << "NO" << endl;
        
    }

    return 0;
}