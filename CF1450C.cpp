//
// Created by ttw on 2020/12/7.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;

char s[305][305];


int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
        }
        int cnt[2][3];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == 'X') {
                    cnt[0][(i + j) % 3]++;
                }
                else if (s[i][j] == 'O') {
                    cnt[1][(i + j) % 3]++;
                }
            }
        }
        int k1 = 0, k2 = 1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (cnt[0][k1] + cnt[1][k2] > cnt[0][i] + cnt[1][j]){
                    k1 = i;
                    k2 = j;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] != '.' && (i + j) % 3 == k1) {
                    s[i][j] = 'O';
                }
                else if (s[i][j] != '.' && (i + j) % 3 == k2) {
                    s[i][j] = 'X';
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << s[i][j];
            }
            cout << endl;
        }
    }



    return 0;
}
