/**
  * @Problem CF1393B.cpp
  * @Time 2020/8/7 22:31
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    map<int, int> w;
    int c2 = 0, c4 = 0, c6 = 0, c8 = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        w[a]++;
        if (w[a] == 8) c8++;
        else if (w[a] == 6) c6++;
        else if (w[a] == 4) c4++;
        else if (w[a] == 2) c2++;
    }
    int q;
    cin >> q;
    while (q--) {
        char o;
        cin >> o;
        int p;
        cin >> p;
        if (o == '-') {
            w[p]--;
            if (w[p] == 7) c8--;
            else if (w[p] == 5) c6--;
            else if (w[p] == 3) c4--;
            else if (w[p] == 1) c2--;
        } else {
            w[p]++;
            if (w[p] == 8) c8++;
            else if (w[p] == 6) c6++;
            else if (w[p] == 4) c4++;
            else if (w[p] == 2) c2++;
        }

        if (c8 || c4 > 1 || c6 && c2 > 1 || c4 && c2 > 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
