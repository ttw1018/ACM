#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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



multiset<int> s, v;

void out() {
    if (s.size() > 1) {
        cout << (*v.rbegin() - *v.begin()) - *s.rbegin() << endl;
    }
    else {
        cout << 0 << endl;
    }
}



int main () {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.insert(a[i]);
    }
    sort(a + 1, a + 1 + n);
    
    for (int i = 2; i <= n; i++) {
        s.insert(a[i] - a[i - 1]);
    }
    out();
    while (q--) {
        int o, x;
        cin >> o >> x;
        if (o == 1) {
            multiset<int>::iterator pos = v.lower_bound(x);
            if (pos != v.end())
                s.insert(*pos - x);
            if (pos != v.begin()) {
                s.insert(x - *(--pos));
                ++pos;
            }
            if (pos != v.end() && pos != v.begin()) {
                int val = *pos - *(--pos);
                pos = s.lower_bound(val);
                s.erase(pos);
            }
            v.insert(x);
        }
        else {
            multiset<int>::iterator pos = v.lower_bound(x);

            // for (auto i : v) {
            //     cout << i << " ";
            // }
            // cout << endl;
            // for (auto i : s) {
            //     cout << i << " ";
            // }
            // cout << endl << endl;


            multiset<int>::iterator now = pos;

            if (now != v.begin()) {
                int val = *pos - *(--now);
                s.erase(s.lower_bound(val));
            }

            now = pos;
            if (now != --v.end()) {
                int val = *(++now) - x;
                s.erase(s.lower_bound(val));
            }

            now = pos;
            if (now != v.begin() && now != --v.end()) {
                multiset<int>::iterator it = pos;
                int val = *(++now) - *(--it);
                // cout << val << endl;
                s.insert(val);
                // cout << "insert yes" << endl;
            }
            v.erase(pos);
            // for (auto i : v) {
            //     cout << i << " ";
            // }
            // cout << endl;

            // for (auto i : s) {
            //     cout << i << " ";
            // }
            // cout << endl << endl;
        }
        out();
        // cout << endl;
    }

    
    



    return 0;
}