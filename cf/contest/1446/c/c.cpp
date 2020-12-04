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

int solve(vector<int> v, int k)
{
    if (k == -1 || v.size() == 1 || v.size() == 0) return 0;

    vector<int> v1, v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] & (1 << k)) {
            v1.push_back(v[i]);
        } else {
            v2.push_back(v[i]);
        }
    }
    if (v1.size() > 1 && v2.size() > 1) {
    return min(v1.size() - 1 + solve(v2, k - 1), v2.size() - 1 + solve(v1, k - 1));
    }
    else if (v1.size() <= 1) {
        return solve(v2, k - 1);
    }
    else if (v2.size() <= 1) {
        return solve(v1, k - 1);
    }

}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), [](int a, int b) {
        return a > b;
    });

    int tmp = a[0];
    int cnt = -1;
    while (tmp) {
        cnt++;
        tmp >>= 1;
    }
    cout << solve(a, cnt) << endl;

    return 0;
}