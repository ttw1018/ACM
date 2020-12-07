/**
  * @Problem nowcoder5668A.cpp
  * @Time 2020/7/18 12:36
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0, ans = 0;
        vector<char> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '2' || s[i] == '3') {
                ans++;
            } else {
                v.push_back(s[i]);
            };
        }

        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == '0') {
                cnt--;
            } else {
                if (cnt < 0) {
                    cnt++;
                    ans++;
                } else {
                    cnt--;
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}
