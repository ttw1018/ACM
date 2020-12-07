/**
  * @Problem CF1400C.cpp
  * @Time 2020/8/25 23:09
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
char s[maxn];
int x;

int ans[maxn];

char t[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> (s + 1);
        cin >> x;

        int len = strlen(s + 1);

        for (int i = 1; i <= len; i++) {
            if (s[i] == '1') {
                if (i - x >= 1) {
                    int now = i - x;
                    if (now - x < 1 || s[now - x] == '1') {
                        ans[now] = 1;
                    }

                }
                if (i + x <= len) {
                    int now = i + x;
                    if (now + x > len || s[now + x] == '1') {
                        ans[now] = 1;
                    }
                }
            }
        }
        int flag = 1;
//        for (int i = 1; i <= len; i++) {
//            if (s[i] == '1') {
//                if ((i + x <= len && ans[i + x] == 1) || (i - x >= 1 && ans[i - x] == 1)) {
//
//                }
//                else {
//                    flag = 0;
//                    break;
//                }
//            }
//        }
        for (int i = 1; i <= len; i++) {
            t[i] = '0';
        }

        for (int i = 1; i <= len; i++) {
            if (ans[i] == 1) {
                if (i + x <= len) t[i + x] = '1';
                if (i - x >= 1) t[i - x] = '1';
            }
        }

        for (int i = 1; i <= len; i++) {
            if (s[i] != t[i]) {
                flag = 0;
            }
        }
        if (flag) {

            for (int i = 1; i <= len; i++) {
                cout << ans[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        for (int i = 1; i <= len; i++) {
            ans[i] = 0;
        }

    }


    return 0;
}
