/**
  * @Problem CF1395C.cpp
  * @Time 2020/8/12 22:54
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int a[205], b[205];

int vis[205];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

//    int ans = 0;
//    vector<int> v, v1[205];
//
//    for (int i = 1; i <= n; i++) {
////        int flag = 0;
//        for (int j = 1; j <= m; j++) {
////            int now = a[i] & b[j];
////            if (now == 0) {
////                flag = 1;
////                break;
////            }
//            v1[i].push_back(b[j]);
//        }
////        if (!flag) {
//            v.push_back(i);
////        }
//    }
//
//    for (int k = 9; k >= 0; k--) {
//        for (auto i : v)  {
//            vector<int> vnow;
//            vnow.clear();
//            for (auto j : v1[i]) {
//                int now = a[i] & j;
//                if ((now & (1 << k)) == 0) {
//                    vnow.push_back(j);
//                }
//            }
//            if (vnow.size() > 0) {
//                v1[i] = vnow;
//            }
//            else {
//                ans |= 1 << k;
//            }
//        }
//    }
//    cout << ans << endl;

    int ans = 0;
    int ma = 1 << 9;
    for (ans = 0; ans < ma; ans++) {
        int can = 1;
        for (int i = 1; i <= n; i++) {
            int flag = 0;
            for (int j = 1; j <= m; j++) {
                int now = a[i] & b[j];
                if ((now | ans) <= ans) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                can = 0;
                break;
            }
        }
        if (can) break;
    }
    cout << ans << endl;

    return 0;
}
