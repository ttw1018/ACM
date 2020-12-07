/**
  * @Problem hduday5_1003.cpp
  * @Time 2020/8/4 14:06
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

int A[405][1025], val[405 * 1025];

int B[1025][2];


void solve(int n, int k) {
    int all = (1 << k) * n * 2;
    for (int i = 1; i <= all; i++) cin >> val[i];
    B[1 << k][0] = 1;
    B[1 << k][1] = all;
    all = 1 << k;

    for (int len = 1; len < all; len <<= 1) {
        for (int j = all - len + 1; j <= all; j++) {
            int p = all - len + 1 + all - len - j;
            B[p][1] = B[j][0];
            int mid = (B[j][0] + B[j][1]) / 2;
            if (B[j][0] > B[j][1]) {
                B[j][0] = mid;
                B[p][0] = mid + 1;
            } else {
                B[j][0] = mid + 1;
                B[p][0] = mid;
            }
        }
    }
    for (int i = 1; i <= all; i++) {
        if (B[i][0] > B[i][1]) {
            int now = B[i][0];
            for (int j = 1; j <= 2 * n; j++) {
                A[j][i] = now--;
            }
        } else {
            int now = B[i][0];
            for (int j = 1; j <= 2 * n; j++) {
                A[j][i] = now++;
            }
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= all; j++) {
//            cout << A[i][j] << " ";
            cout << val[A[i][j]];
            if (i == 2 * n && j == all) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
//        cout << endl;
    }
//    cout << endl;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }


    return 0;
}
