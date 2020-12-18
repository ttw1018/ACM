#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

int a[505][505];
int p[250005];

int b[505];


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
                p[a[i][j]] = i;
            }
        }

        for (int j = 1; j < m; j++) {
            for (int i = 1; i <= n; i++) {
                int x;
                scanf("%d", &x);
            }
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            int l = p[b[i]];
            for (int j = 1; j <= m; j++) {
                printf("%d ", a[l][j]);
            }
            printf("\n");
        }
    }
    return 0;
}