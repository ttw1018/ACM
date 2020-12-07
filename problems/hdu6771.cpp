/**
  * @Problem hdu6771.cpp
  * @Time 2020/7/25 9:13
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, m, q;
int x, y;
char s[100005];
int A[405][405];

int pos[405][2];

void go(int &x, int &y, char c) {
    if (c == 'L') {
        x--;
    } else if (c == 'R') {
        x++;
    } else if (c == 'D') {
        y--;
    } else {
        y++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        while (q--) {
            scanf("%d %d", &x, &y);
            scanf("%s", s);
            int len = strlen(s);

            for (int i = 0; i <= n; i++) {
                pos[i][0] = m + 1;
                pos[i][1] = -1;
            }
            for (int i = 0; i < len; i++) {
                go(x, y, s[i]);
                pos[y][0] = min(pos[y][0], x);
                pos[y][1] = max(pos[y][1], x);
            }

//            for (int i = 0; i <= n; i++) {
//                cout << pos[i][0] << " " << pos[i][1] << endl;
//            }
            map<int, int> w;
            for (int i = 1; i <= n; i++) {
                int l = max(pos[i][0], pos[i - 1][0]);
                int r = min(pos[i][1], pos[i - 1][1]);
                for (int j = l + 1; j <= r; j++) {
                    w[A[i][j]] = 1;
                }
            }
            printf("%d\n", w.size());
        }
    }


    return 0;
}
