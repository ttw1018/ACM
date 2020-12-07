/**
  * @Problem CF1450C.cpp.c
  * @Time 2020/12/6 22:22
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[305][305];
int cnt[305][305];

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j + 2 <= n; j++) {
                int flag = 1;
                for (int k = 0; k < 3; k++) {
                    if (s[i][j + k] != 'X') {
                        flag = 0;
                    }
                }
                if (!flag) continue;
                if (i + 2 <= n) {
                    int pos = -1;
                    for (int k = 0; k < 3; k++) {
                        int flag = 1;
                        for (int d = 0; d < 3; d++) {
                            if (s[i + d][j + k] != 'X') {
                                flag = 0;
                            }
                        }
                        if (flag) {
                            pos = k;
                            break;
                        }
                    }
                    if (pos != -1) {
                        s[i][j + pos] = 'O';
                        j += pos;
                    }
                    else {
                        s[i][j + 2] = 'O';
                        j += 2;
                    }

                }
                else {
                    s[i][j + 2] = 'O';
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
