/**
  * @Problem CF1440C.cpp
  * @Time 2020/11/17 22:57
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


char s[105][105];


vector<pair<int, int>> solve(map<pair<int, int>, char> w) {
    vector<pair<int, int>> v1, v2;
    for (auto i : w) {
        if (i.second == '0') {
            v1.push_back(i.first);
        } else {
            v2.push_back(i.first);
        }
    }
//    cout << v1.size() <<  " " << v2.size() << endl;
    vector<pair<int, int>> ans;
    if (v1.size() == 4) {
        return ans;
    }
    if (v1.size() == 3) {
        ans.push_back(v1[0]);
        ans.push_back(v1[1]);
        ans.push_back(v2[0]);
        ans.push_back(v1[0]);
        ans.push_back(v1[2]);
        ans.push_back(v2[0]);
        ans.push_back(v1[1]);
        ans.push_back(v1[2]);
        ans.push_back(v2[0]);
        return ans;
    }
    if (v1.size() == 2) {
        ans.push_back(v1[0]);
        ans.push_back(v1[1]);
        ans.push_back(v2[0]);
        ans.push_back(v1[0]);
        ans.push_back(v1[1]);
        ans.push_back(v2[1]);
        return ans;
    }
    if (v1.size() == 1) {
        return v2;
    }
    ans.push_back(v2[0]);
    ans.push_back(v2[1]);
    ans.push_back(v2[2]);
    ans.push_back(v2[0]);
    ans.push_back(v2[1]);
    ans.push_back(v2[3]);
    ans.push_back(v2[1]);
    ans.push_back(v2[2]);
    ans.push_back(v2[3]);
    ans.push_back(v2[0]);
    ans.push_back(v2[2]);
    ans.push_back(v2[3]);
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
        }
        int cnt = 0;
        vector<pair<int, int>> res;
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= m; j += 2) {
//                cout << i << " " << j << endl;
                map<pair<int, int>, char> w;
                w[{i, j}] = s[i][j];
                int x, y;
                if (i + 1 <= n) {
                    w[{i + 1, j}] = s[i + 1][j];
                    x = i + 1;
                } else {
                    w[{i - 1, j}] = '0';
                    x = i - 1;
                }
                if (j + 1 <= m) {
                    w[{i, j + 1}] = s[i][j + 1];
                    y = j + 1;
                } else {
                    w[{i, j - 1}] = '0';
                    y = j - 1;
                }
                if (x == i + 1 && y == j + 1)
                    w[{x, y}] = s[x][y];
                else
                    w[{x, y}] = '0';

                vector<pair<int, int>> ans;
                ans = solve(w);
                for (auto i : ans) {
                    res.push_back(i);
                }
            }

        }
        cout << res.size() / 3 << endl;
        for (int i = 0; i < res.size(); i += 3) {
            cout << res[i].first << " " << res[i].second
                 << " " << res[i + 1].first << " " << res[i + 1].second
                 << " " << res[i + 2].first << " " << res[i + 2].second << endl;
        }
    }


    return 0;
}
