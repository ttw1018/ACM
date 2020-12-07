/**
  * @Problem hduday4_1004.cpp
  * @Time 2020/7/30 13:39
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

int n, m, s, t, d;

const int maxn = 1e5 + 5;
char str[maxn];


struct edge {
    int from, to, val;

    edge(int a, int b, int c) : from(a), to(b), val(c) {}
} e[maxn * 2];

int head[maxn], tot = 1;

void add(int x, int y, int v) {
    e[++tot] = edge(head[x], y, v);
    head[x] = tot;
    e[++tot] = edge(head[y], x, v);
    head[y] = tot;
}


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &d);
        scanf("%s", str + 1);

        for (int i = 0; i < m; i++) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            add(a, b, w);
        }


    }


    return 0;
}
