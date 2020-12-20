//
// Created by ttw on 2020/12/18.
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
const int maxn = 3e5 + 5;

int a[maxn];

vector<int> v[maxn];

int p[maxn];
int fa[maxn];

int in[maxn];
int son[maxn];

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) p[i] = son[i] = i;

    for (int i = 1; i <= k; i++) {
        int l, r;
        cin >> l >> r;
        p[r] = l;
        son[l] = r;
        v[l].push_back(r);
        in[r]++;
    }

    for (int i = 1; i <= n; i++) {
        int now = i;
        int cnt = 0;
        while (p[now] != now) {
            now = p[now];
            cnt++;
            if (cnt > n) {
                cout << 0 << endl;
                return 0;
            }
        }
        p[i] = now;
    }
    for (int i = 1; i <= n; i++) {
        int now = i;
        int cnt = 0;
        while (son[now] != now) {
            now = son[now];
            cnt++;
            if (cnt > n) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << son[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;



    return 0;
}
