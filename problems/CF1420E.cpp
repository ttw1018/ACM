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
#include <yvals_core.h>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;


int a[100];

vector<int> v;

int main () {
    int n;
    cin >> n;
    int cnt = 0;
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) {
            v.push_back(i - pre - 1);
            pre = i;
            cnt++;
        }
    }
    v.push_back(n - pre);
    
    int ans = 0;
    
    ans = (n - cnt) * (n - cnt);
    
    for (auto i : v) {
        ans -= i * i;
    }
    
    cout << ans << " ";
    

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] - v[i + 1] > 1) {
            ans += v[i] * v[i] + v[i + 1] * v[i + 1];
            v[i]--;
            v[i + 1]++;
            ans -= v[i] * v[i] + v[i + 1] * v[i + 1];
        }
    }
    
    return 0;
}