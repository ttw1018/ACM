/**
  * @Problem hduday8_1008.cpp
  * @Time 2020/8/13 13:22
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

vector<int> v;
#define out(x)  printf("%d", x), v.push_back(x);


char vis[1000][1000];

int x, y;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        v.clear();
        int n;
        scanf("%d", &n);
        if (n & 1) {
            out(1);
            out(3);
            out(2);
            out(6);
            out(2);
            out(1);
            out(5);
            out(1);
            out(6);
            out(4);
            out(6);
            out(5);
            out(4);
            out(2);
            out(3);
            out(5);
            out(4);
            out(6);
        }
        if (n > 3 && n & 1) {
            out(5)
            for (int i = 4; i < n; i += 2) {
                int a = 2;
                int b = 2, c = 6;
                out(6);
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < i - 1; k++) {
                        out(b)
                        out(c)
                    }
                    out(a);
                    a = a % 6 + 1;
                    b = b % 6 + 1;
                    c = c % 6 + 1;
                }

                for (int k = 0; k < i - 2; k++) {
                    out(b)
                    out(c)
                }
                out (6);
                if (i + 2 < n) out(5);
            }

        } else if ((n & 1) == 0) {
            for (int i = 1; i < n; i += 2) {
                int a = 2;
                int b = 2, c = 6;
                out(6);
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < i - 1; k++) {
                        out(b)
                        out(c)
                    }
                    out(a);
                    a = a % 6 + 1;
                    b = b % 6 + 1;
                    c = c % 6 + 1;
                }

                for (int k = 0; k < i - 2; k++) {
                    out(b)
                    out(c)
                }
                if (i > 2)
                    out (6);
                if (i + 2 < n) out(5);
            }
        }
        puts("");

//
//        memset(vis, '.', sizeof(vis));
//        x = 20, y = 20;
//        vis[x][y] = '*';
//        for (auto i : v) {
//            if (i == 1) x--, y--;
//            if (i == 2) x--, y++;
//            if (i == 3) y += 2;
//            if (i == 4) x++, y++;
//            if (i == 5) x++, y--;
//            if (i == 6) y -= 2;
//            vis[x][y] = '0';
//            if (x == 20 && y == 20) {
//                cout << i << " ";
//                cout << "DD" << endl;
//            }
//        }
//
//        for (int i = 0; i < 50; i++) {
//            for (int j = 0; j < 50; j++) {
//                cout << vis[i][j] ;
//            }
//            cout << endl;
//        }
//
//        int cnt = 0;
//        for (int i = 1; i < v.size(); i++) {
//            if (v[i] == v[i - 1]) cnt++;
//        }
//        cout << cnt << endl;




    }


    return 0;
}
