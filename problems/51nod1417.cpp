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
const int maxn = 1e8 + 5;

int sg[70];
bool vis[maxn];

void dfs(int cur, int yu, int ans, int next) {
    if (yu == 0) {
        vis[ans] = 1;
        return ;
    }
    for (int i = next; i < cur; i++) {
        dfs(cur, yu - 1, ans ^ sg[i], i);
    }
}

void init () {
    sg[0] = 0;
    for (int i = 1; i <= 64; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, 7, 0, 0);
        for (int j = 0; ; j++) {
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
        }
        cout << sg[i] << endl;
    }
}

int main () {
    while(1) {
        cout << "hello world" << endl;
    }
    init();

    return 0;
}