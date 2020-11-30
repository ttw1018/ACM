#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7
//const int mod = 998244353;

const int maxn = 1e5 + 5;

int c[maxn][26];
int cnt = 0;

void insert(string s)
{
    int now = 0;
    for (int i = 0; i < s.length(); i++) {
        int to = s[i] - 'a';
        if (c[now][to]) {
            now = c[now][to];
        } else {
            c[now][to] = ++cnt;
            now = cnt;
        }
    }
}

int sg[maxn];

void dfs(int x)
{
    int vis = 0;
    for (int i = 0; i < 26; i++) {
        if (c[x][i]) {
            dfs(c[x][i]);
            vis = 1;
            sg[x] |= 3 ^ sg[c[x][i]];
        }
    }
    if (!vis) {
        sg[x] = 1;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s);
        
    }
    dfs(0);
    if (sg[0] == 1 || sg[0] == 0) {
        puts("Second");
    }
    else if (sg[0] == 2) {
        if (k & 1) puts("First");
        else puts("Second");
    }
    else if (sg[0] == 3) {
        puts("First");
    }

    



    return 0;
}