//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;

vector<int> v[maxn];
int a[maxn];

int ans = 0;

void dfs(int now, int sta) {
    if (sta) ans ^= a[now];
    for (auto i : v[now]) {
        dfs(i, sta ^ 1);
    }
}


int main () {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) v[i].clear();
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ans = 0;
        dfs(0, 0);
        if (ans) {
            cout << "win" << endl;
        }
        else {
            cout << "lose" << endl;
        }

    }
    
    
    
    
    return 0;
}