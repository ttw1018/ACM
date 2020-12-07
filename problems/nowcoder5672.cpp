/**
  * @Problem nowcoder5672.cpp
  * @Time 2020/8/2 12:55
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

int ans[30][30], var[30][30][30];
string opt1[205], opt2[205];


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string ss;
        cin >> opt1[i] >> ss >> opt2[i];
    }

    for (int cnt = 1; cnt < 100; cnt++) {
        for (int i = 1; i <= n; i++) {
            int len1 = opt1[i].length();
            int len2 = opt2[i].length();
            if (len1 == 1) {
                if (len2 == 1 && opt2[i][0] >= 'a' && opt2[i][0] <= 'z') {
                    ans[opt1[i][0] - 'A' + 1][opt2[i][0] - 'a' + 1] = 1;
                } else if (len2 == 1) {
                    for (int j = 1; j <= 26; j++) {
                        ans[opt1[i][0] - 'A' + 1][j] |= ans[opt2[i][0] - 'A' + 1][j];
                    }
                } else {
                    for (int j = 1; j <= 26; j++) {
                        if (ans[opt2[i][0] - 'A' + 1][j]) {
                            for (int k = 1; k <= 26; k++) {
                                ans[opt1[i][0] - 'A' + 1][k] |= var[j][opt2[i][2] - 'a' + 1][k];
                            }
                        }
                    }
                }
            } else {
                for (int j = 1; j <= 26; j++) {
                    if (ans[opt1[i][0] - 'A' + 1][j]) {
                        for (int k = 1; k <= 26; k++) {
                            var[j][opt1[i][2] - 'a' + 1][k] |= ans[opt2[i][0] - 'A' + 1][k];
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 26; i++) {
        cout << char('A' + i - 1) << ": ";
        for (int j = 1; j <= 26; j++) {
            if (ans[i][j]) {
                cout << char('a' + j - 1);
            }
        }
        cout << endl;
    }


    return 0;
}


