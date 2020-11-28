//
// Created by ttw on 2020/11/26.
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

//const int maxn = 105;

int A[105][105];

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)  {
                cin >> A[i][j];
                cnt += A[i][j];
            }
        }
        if (cnt & 1) {
            cout << "yadang" << endl;
        }
        else {
            cout << "xiawa" << endl;
        }
    }


    return 0;
}
