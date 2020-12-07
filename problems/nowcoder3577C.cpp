/**
  * @Problem nowcoder3577C.cpp
  * @Time 2020/7/18 10:34
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int mod = 1e9 + 7;

int start[1000], ed[1000];
vector<int> v[1000];
int len;
int cnt = 0;

vector<int> ans;

bool dfs(int x) {
    if (x == len) {
        ans.push_back(x);
        cnt++;
        return true;
    }
    int flag = 0;
    for (auto to : v[x]) {
        if (dfs(to)) {
            ans.push_back(x);
            flag = 1;
        }
    }
    return flag;
}


int main() {
    int n;
    cin >> n;
    map<string, int> w;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        w[s] = 1;
    }
    string s;
    cin >> s;
    len = s.length();

    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length() - i; j++) {
            string now = s.substr(i, j);
            if (w[now]) {
                v[i].push_back(j + i);
            }
        }
    }
    dfs(0);
    if (cnt == 0) {
        cout << "IMPOSSIBLE!" << endl;
    } else if (cnt == 1) {
        reverse(ans.begin(), ans.end());
        int now = 0;
        for (int i = 1; i < ans.size(); i++) {
            for (int j = now; j < ans[i]; j++) {
                cout << s[j];
            }
            now = ans[i];
            cout << " ";
        }


    } else {
        cout << "AMBIGUOUS!" << endl;
    }


    return 0;
}
