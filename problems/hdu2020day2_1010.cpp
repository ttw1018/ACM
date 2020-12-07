/**
  * @Problem hdu2020day2_1010.cpp
  * @Time 2020/7/23 13:38
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, k;

struct node {
    int a, b, c, d;

    node(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {};

};

bool cmp(vector<node> a, vector<node> b) {
    return a.size() < b.size();
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        vector<node> vv[55];

        for (int i = 1; i <= n; i++) {
            int x, a, b, c, d;
            scanf("%d%d%d%d%d", &x, &a, &b, &c, &d);

            vv[x].push_back(node(a, b, c, d));
        }


        printf("%lld\n", ans);

    }

    return 0;
}
