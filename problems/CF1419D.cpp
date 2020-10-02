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
const int maxn = 1e5 + 5;

int a[maxn];
int ans[maxn];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ans[n + 1] = 0;
    
    for (int i = 1; i <= n; i += 2) {
        ans[i] = a[n - (i / 2)];
    }
    
    int cnt = 0;
    stack<int> q;
    vector<int> v;
    for (int i = 2; i <= n; i += 2) {
        q.push(a[i / 2]);
    }
    int pos = 0;
    for (int i = 2; i <= n; i += 2) {
        int now = min(ans[i - 1], ans[i + 1]);
        while (q.size() && q.top() >= now) {
            v.push_back(q.top());
            q.pop();
        }
        if (q.empty()) {
            pos = i;
            break;
        }
        ans[i] = q.top();
        q.pop();
        
    }
    if (v.size())
        cout << pos / 2  - 1 << endl;
    else {
        cout << (n + 1) / 2 - 1  << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        ans[pos] = v[i];
        pos += 2;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    
    
    



    return 0;
}