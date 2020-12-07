/**
  * @Problem nowcoder5673G.cpp
  * @Time 2020/8/3 16:26
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


int vis[4][4][4][4];

int get(string s) {
    if (s == "*") return 3;
    if (s == "one") return 0;
    if (s == "two") return 1;
    if (s == "three") return 2;
    if (s == "diamond") return 0;
    if (s == "squiggle") return 1;
    if (s == "oval") return 2;
    if (s == "solid") return 0;
    if (s == "striped") return 1;
    if (s == "open") return 2;
    if (s == "red") return 0;
    if (s == "green") return 1;
    if (s == "purple") return 2;
}

vector<int> v[4][4][4][4];

int A[300][4];


bool check(int a, int b) {
    for (int i = 0; i < 4; i++) {
        if
    }

}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(vis, 0, sizeof(vis));
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int now = 1;
            int cnt[4];
            int c = -1;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == ']') {
                    string a = s.substr(now, j - now);
                    cnt[++c] = get(a);
                    A[i][c] = cnt[c];
                    now = j + 2;

                }
            }
            vis[cnt[0]][cnt[1]][cnt[2]][cnt[3]]++;
            v[cnt[0]][cnt[1]][cnt[2]][cnt[3]].push_back(i);
        }
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (check(i, j)) goto ed;

            }
        }
        ed:;
    }

    return 0;
}
