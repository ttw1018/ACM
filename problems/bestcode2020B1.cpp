/**
  * @Problem bestcode2020B1.cpp
  * @Time 2020/7/19 14:20
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    vector<pair<int, double>> v;
    v.push_back(make_pair(60, 1.0));
    v.push_back(make_pair(62, 1.7));
    v.push_back(make_pair(65, 2.0));
    v.push_back(make_pair(67, 2.3));
    v.push_back(make_pair(70, 2.7));
    v.push_back(make_pair(75, 3.0));
    v.push_back(make_pair(80, 3.3));
    v.push_back(make_pair(85, 3.7));
    v.push_back(make_pair(90, 4.0));
    v.push_back(make_pair(95, 4.3));
    while (T--) {
        int x;
        cin >> x;
        double ans = 0;
        int sum = 0;
        int siz = v.size();
        double res;
        for (int a = 0; a < siz; a++) {
            sum = v[a].first;
            if (sum <= x) res = v[a].second;
            else {
                ans = max(ans, res);
                break;
            }
            int sum1 = sum;
            double res1 = res;

            for (int b = a; b < siz; b++) {
                sum = sum1 + v[b].first;
                if (sum <= x) res = res1 + v[b].second;
                else {
                    ans = max(ans, res);
                    break;
                }
                int sum2 = sum;
                double res2 = res;
                for (int c = b; c < siz; c++) {
                    sum = sum2 + v[c].first;
                    if (sum <= x) res = res2 + v[c].second;
                    else {
                        ans = max(ans, res);
                        break;
                    }
                    int sum3 = sum;
                    double res3 = res;
                    for (int d = c; d < siz; d++) {
                        sum = sum3 + v[d].first;
                        if (sum <= x) res = res3 + v[d].second;
                        ans = max(ans, res);
                    }
                }
            }
        }
        printf("%.1f\n", ans);

    }


    return 0;
}
