#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7
//const int mod = 998244353;

const int maxn = 1e5 + 5;

char c[maxn][26];
int cnt = 0;

void insert(string s) {
    int now = 0;
    for (int i = 0; i < s.length(); i++) {
        int to = s[i] - 'a';
        if (c[now][to]) {
            now = c[now][to];
        }
        else {
            c[now][to] = ++cnt;
            now = cnt;
        }
    }
}

void dfs(int x) {
    int vis = 0;
    for (int i = 0; )
}

int main () {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    dfs(0);





    return 0;
}