/**
  * @Problem CF1375D.cpp
  * @Author Tianwen Tang
  * @Time 2020/7/12 11:14
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e3 + 5;

int A[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int vis[maxn];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            vis[A[i]]++;
        }
        set<int> s;
        for (int i = 0; i <= n; i++) {
            if (!vis[i]) s.insert(i);
        }
        vector<int> ans;
        while (true) {
            int a = *s.begin();
//            cout << a << endl;
            s.erase(s.begin());
            if (a == 0) {
                int flag = 1;
                for (int i = 1; i <= n; i++) {
                    if (A[i] != i) {
                        vis[A[i]]--;
                        if (!vis[A[i]]) s.insert(A[i]);
                        A[i] = 0;
                        flag = 0;
                        vis[0]++;
                        ans.push_back(i);
                        break;
                    }
                }
                if (flag) break;
                continue;
            }
            vis[A[a]]--;
            if (vis[A[a]] == 0) {
                s.insert(A[a]);
            }
            A[a] = a;
            vis[a]++;
            ans.push_back(a);
        }
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}
