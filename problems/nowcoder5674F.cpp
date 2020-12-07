/**
  * @Problem nowcoder5674F.cpp
  * @Time 2020/8/8 13:37
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

vector<pair<int, int>> v;
const int maxn = 1e6 + 5;
int cnt[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int val;
            scanf("%d", &val);
            v.push_back(make_pair(val, i));
        }
    }
    sort(v.begin(), v.end());
    queue<pair<int, int>> q;

    int all = 0;
    int ans = 1e9;
    for (int i = 0; i < v.size(); i++) {
        q.push(v[i]);
        cnt[v[i].second]++;
        if (cnt[v[i].second] == 1) all++;

        while (cnt[q.front().second] > 1) {
            cnt[q.front().second]--;
            q.pop();
        }

        while (all > m) {
            pair<int, int> p = q.front();
            q.pop();
            cnt[p.second]--;
            if (cnt[p.second] == 0) all--;
        }
        if (all == m)
            ans = min(ans, v[i].first - q.front().first);

    }
    cout << ans << endl;


    return 0;
}
