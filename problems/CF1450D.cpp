/**
  * @Problem CF1450D.cpp.c
  * @Time 2020/12/6 22:23
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;

int a[maxn];

int n;

int t[maxn];

int lowbit(int x) {
    return x & (-x);
}
void add (int x) {
//    cout << x << endl;
    while (x > 0) {
        t[x]++;
        x -= lowbit(x);
    }
}

int que (int x) {
    int ans = 0;
    while (x <= n) {
        ans += t[x];
        x += lowbit(x);
    }
    return ans;
}

vector<int> v[maxn];

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v[a[i]].push_back(i);
        }
        set<int> s;
        for (int i = 1; i <= n; i++) t[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i].size() > 0) {
                    int len = 1;
                    for (auto j : v[i]) {
                        int l, r;
                        set<int>::iterator ll = s.lower_bound(j);
                        set<int>::iterator rr = ll;
                        if (ll != s.begin()) {
                            l = *(--ll) + 1;
                        }
                        else {
                            l = 1;
                        }
                        if (rr != s.end()) {
                            r = (*rr) - 1;
                        }
                        else {
                            r = n;
                        }
                        len = max(len, min(n - i + 1, r - l + 1));
                    }
                    add(len);
                for (auto j : v[i]) {
                    s.insert(j);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (que(i) == n - i + 1) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }


    return 0;
}
