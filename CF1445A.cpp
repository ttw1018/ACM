//
// Created by ttw on 2020/11/1.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn], b[maxn];

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] + b[n - i + 1] > x) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }

    }


    return 0;
}
