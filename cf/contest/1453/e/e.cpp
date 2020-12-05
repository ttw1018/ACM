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

const int maxn = 2e5 + 5;

vector<int> e[maxn];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }

    }

    return 0;
}