/**
  * @Problem nowcoder1443E.cpp
  * @Time 2020/11/17 22:22
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll c[20];

vector<int> ans;

void solve(int n, int x) {
    vector<int> v, ans;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        int p = x / c[i];
        ans.push_back(v[p]);
        v.erase(v.begin() + p);
        x %= p;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    ll cnt = 0;
    for (int i = 1; i <= 15; i++) {
        c[i] = c[i - 1] * i;
    }

    solve(4, 1);

    while (n--) {
        int ope;
        cin >> ope;
        if (ope == 1) {
            int l, r;
            cin >> l >> r;

        } else {
            int x;
            cin >> x;
            cnt += x;


        }

    }


    return 0;
}

