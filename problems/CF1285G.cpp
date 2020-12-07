#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int A[maxn][2];

bool vis[maxn];
vector<int> v[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i][0]);
            v[A[i][0]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i][1]);
            v[A[i][1]].push_back(i);
        }

        int bad = 0;

        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            if (v[i].size() != 2) {
                bad = 1;
                break;
            }
        }
        if (bad) {
            printf("-1\n");
            continue;
        }
        vector<int> ans;
        ans.clear();

        for (int i = 1; i <= n; i++) {
            if (A[i][0] == A[i][1]) {
                vis[i] = 1;
                continue;
            }
            if (vis[i]) {
                continue;
            }
            int now = i;
            vector<int> v1, v2;
            int st = now;
            v1.push_back(now);
            while (!vis[now]) {
                vis[now] = 1;
                int b = A[now][1];
                int nex;
                if (v[b][0] == now) nex = v[b][1];
                else nex = v[b][0];

                now = nex;
                if (now == st) break;

                if (A[now][0] == b) {
                    v1.push_back(now);
                } else {
                    v2.push_back(now);
                    swap(A[now][0], A[now][1]);
                }
            }
            if (v1.size() < v2.size()) {
                for (auto j : v1) {
                    ans.push_back(j);
                }
            } else {
                for (auto j : v2) {
                    ans.push_back(j);
                }
            }
        }
        printf("%d\n", ans.size());
        for (auto i : ans) {
            printf("%d ", i);
        }
        puts("");
    }
    return 0;

}










