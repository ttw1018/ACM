/**
  * @Problem bestcodefu1002.cpp
  * @Time 2020/8/9 19:14
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e6 + 5;

char s[maxn], s1[maxn];

int suff[maxn], pre1[maxn], pre2[maxn];


int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> s + 1 >> s1 + 1;
        s[n + 1] = '0';
        s1[n + 1] = '0';

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            pre1[i] = pre1[i - 1] + (s[i] == '0');
            pre2[i] = pre2[i - 1] + (s1[i] == '1');
        }

        suff[n + 2] = 0;
        suff[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            suff[i] = suff[i + 1] + (s[i] != s1[i]);
        }
//
//        for (int i = 1; i <= n; i++) {
//            cout << pre1[i] << " ";
//        }
//        cout << endl;
//        for (int i = 1; i <= n; i++) {
//            cout << pre2[i] << " ";
//        }
//        cout << endl;

        int ans = suff[1];
        for (int i = 1; i <= n; i++) {
            int res = 0;
            if (s[i + 1] == '1') res++;

            res += 1 + pre1[i] + pre2[i] + suff[i + 2] + (s1[i + 1] == '0');
//            if (res == 1) {
//                cout << i << endl;
//                cout << s1[i + 1] << endl;
//            }

            ans = min(ans, res);
        }
        cout << ans << endl;
//        cout << endl;



    }


    return 0;
}
