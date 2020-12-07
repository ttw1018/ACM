/**
  * @Problem CF1382C.cpp
  * @Time 2020/7/21 22:56
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

char rev(char s) {
    if (s == '0') return '1';
    else return '0';
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int k = n - i;
            int x0;
            if (k & 1) {
                x0 = k / 2;
                if (a[x0] == b[i]) {
                    ans.push_back(1);
                }
            } else {
                x0 = i + k / 2;
                if (a[x0] != b[i]) {
                    ans.push_back(1);
                }
            }
            ans.push_back(i + 1);
        }
        cout << ans.size() << " ";
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;

    }


    return 0;
}
