#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 1e5 + 5;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        map<int, int> w;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (w.find(a) != w.end()) {
                cnt++;
            }
            else {
                w[a] = 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            int a;
            cin >> a;
            if (w.find(a) == w.end()) {
                continue;
            }
            else {
                cnt++;
            }
        }
        cout << cnt << endl;
        
    }
    

    return 0;
}