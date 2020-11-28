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

ll f[50];

int main () {
    int T;
    cin >> T;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 50; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
//    cout << f[49] << endl;
    a:
    while(T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "B" << endl;
            continue;
        }
        for (int i = 2; i < 50; i++) {
            if (n == f[i]) {
                cout << "B" << endl;
                goto a;
            }
        }
        cout << "A" << endl;
    }


    return 0;
}


