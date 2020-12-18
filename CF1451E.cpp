#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
// const int mod = 1e9 + 7;

int a[maxn];
vector<int> v[maxn];
int ans[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cout << "XOR " << 1 << " " << i << endl;
        cout.flush();
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    int flag = 1;
    int pos;
    for (int i = 0; i < n; i++) {
        if (v[i].size() > 1) flag = 0, pos = i;
    }
    if (flag) {
        int p = v[n - 1][0];
        if (p == 2) {
            ans[3] = 0;
            cout << "AND 1 " << 3 << endl;
            cout.flush();
            int x;
            cin >> x;
            ans[3] += x;
            cout << "AND " << p << " " << 3 << endl;
            cout.flush();
            cin >> x;
            ans[3] += x;
            ans[1] = (a[3] ^ ans[3]);
        } else {
            ans[2] = 0;
            cout << "AND 1 " << 2 << endl;
            cout.flush();
            int x;
            cin >> x;
            ans[2] += x;
            cout << "AND " << p << " " << 2 << endl;
            cout.flush();
            cin >> x;
            ans[2] += x;
            ans[1] = a[2] ^ ans[2];
        }
    } else {
        int a1 = v[pos][0];
        int a2 = v[pos][1];
        cout << "AND " << a1 << " " << a2 << endl;
        int x;
        cin >> x;
        ans[a1] = x;
        ans[1] = a[a1] ^ x;
    }
    for (int i = 2; i <= n; i++) {
        ans[i] = a[i] ^ ans[1];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}

