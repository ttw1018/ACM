/**
  * @Problem nowcoder5672B.cpp
  * @Time 2020/8/1 14:12
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> v;
        int n, m;
        cin >> n >> m;
        int ans = 0;
        while (n) {
            int cnt = m / n * n;
            ans += cnt;
            for (int i = 1; i <= cnt; i++) {
                v.push_back(n);
            }
            int temp = n;
            n = m % n;
            m = temp;
        }
        cout << ans << endl;
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }


    return 0;
}
