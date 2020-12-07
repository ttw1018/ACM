/**
  * @Problem CF1372C.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/12 8:28
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == i + 1) {
                v.push_back(a);
            }
        }
        if (v.size() == n) {
            cout << 0 << endl;
            continue;;
        }
        int l = 0, r = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == i + 1) {
                l++;
            } else {
                break;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[v.size() - 1 - i] == n - i) {
                r++;
            }
        }
        if (l + r == v.size()) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }


    return 0;
}
