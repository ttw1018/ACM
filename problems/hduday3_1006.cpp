/**
  * @Problem hduday3_1006.cpp
  * @Time 2020/7/28 13:46
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int num[20];
ll dp[20][2][20][2][10];

ll dfs(int len, int lim, int sum, int zero, int d) {
    if ()
}


ll solve(ll a, int d) {
    memset(dp, -1, sizeof(dp));
    int len = 0;
    while (a) {
        num[++len] = a % 10;
        a /= 10;
    }
    return dfs(len, 1, 0, 1, d);
}


int main() {


    return 0;

}
