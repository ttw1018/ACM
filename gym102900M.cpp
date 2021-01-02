//
// Created by ttw on 2020/12/19.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int n, m;

struct node {
    int cnt;
    set<string> f1, f2;
    map<string, int> dir;
} t[maxn];

int cnt = 0;

void insert(string s, int id) {
    string name = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '/') {
            name = s.substr(0, i);
            s = s.substr(i + 1, s.length() - i - 1);
            break;
        }
    }
    if (name.length() == 0) {
        t[id].f1.insert(s);
        return;
    }
    if (t[id].dir.find(name) == t[id].dir.end()) {
        t[id].dir.insert({name, ++cnt});
        insert(s, cnt);
    }
    else {
        id = t[id].dir[name];
        insert(s, id);
    }
}

void insert1(string s, int id) {
//    cout << s << endl;
    string name = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '/') {
            name = s.substr(0, i);
            s = s.substr(i + 1, s.length() - i - 1);
            break;
        }
    }
    if (name.length() == 0) {
        t[id].f2.insert(s);
        t[id].cnt = 1;
        return;
    }
    if (t[id].dir.find(name) == t[id].dir.end()) {
        t[id].dir.insert({name, ++cnt});
        insert1(s, cnt);
    }
    else {
        id = t[id].dir[name];
        insert1(s, id);
    }
    t[id].cnt = 1;
}

int dfs (int id) {
    if (!t[id].cnt) {
        return 1;
    }
    int ans = 0;
    ans += t[id].f1.size();
    for (auto to : t[id].dir) {
        if (!t[to.second].cnt) ans++;
        else ans += dfs(to.second);
    }
    return ans;

}

void solve() {
    t[0].cnt = 1;
    cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s, 0);
    }
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        insert1(s, 0);
    }

    cout << dfs(0) << endl;


    for (int i = 0; i <= cnt; i++) {
        t[i].cnt = 0;
        t[i].dir.clear();
        t[i].f1.clear();
        t[i].f2.clear();
    }

}

int main () {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}
