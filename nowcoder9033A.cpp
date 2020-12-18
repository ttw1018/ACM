#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const double eps = 1e-6;


int main() {
    int n, m, p;
    while (cin >> n >> m >> p) {

        vector<double> v;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(x * 0.85 + y * 0.15);
        }
        sort(v.begin(), v.end(), [](double &x, double &y) {
            return x > y;
        });

        double x = v[m - 1];

        int ans = (x - 0.15 * p) / 0.85;


        while (ans * 0.85 + 0.15 * p < x - eps) ans++;
        ans = max(ans, 0);
        cout << ans << endl;
    }


    return 0;
}