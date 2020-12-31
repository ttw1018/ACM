/**
  * @Problem B.cpp.c
  * @Time 2020/12/31 21:18
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn], b[maxn];
int vis[105];

int main() {
    int n, y;
    cin >> n >> y;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= y;
        sum = (sum + a[i]) % y;
    }
    set<int> s;
    s.insert(sum);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] %= y;
        set<int> ss;
        for (auto j : s) {
            ss.insert((j - b[i] + y) % y);
            ss.insert((j + b[i]) % y);
        }
        for (auto j : ss) {
            s.insert(j);
        }
    }
    cout << *s.rbegin() << endl;

    return 0;
}
