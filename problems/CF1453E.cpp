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
// const int mod = 1e9 + 7;
const int maxn = 2e3 + 5;

struct node {
    int l, r;
    bool operator < (const node a) const {
        return l < a.l;
    }
} a[maxn];


int main () {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> a[i].l >> a[i].r;
    }
    
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++) {
            
        }
    }


    
    
    
    return 0;
}