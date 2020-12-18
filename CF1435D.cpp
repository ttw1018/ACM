#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;


const int maxn = 1e5 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

bool vis[maxn];
int ans[maxn];

struct node {
    char c;
    int id;
} qu[maxn * 2];

int main() {
    int n;
    cin >> n;
    int ma = n;
    set<int> s;
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int cnt = 0;
    priority_queue<int> have;
    int pre = 0;
    for (int i = 1; i <= n * 2; i++) {
        char c;
        cin >> c;
        qu[i].c = c;
        if (c == '+') {
            while (q.size() && vis[q.top()]) {
                q.pop();
            }
            s.insert(q.top());
            q.pop();
            cnt++;
            have.push(cnt);
        } else {
            int id;
            cin >> id;
            qu[i].id = id;
            vis[id] = 1;
            if (!s.size() || id > *s.begin()) {
                cout << "NO" << endl;
                return 0;
            }
            if (have.size()) {
                if (have.top() != cnt && id < pre) {
                    cout << "NO" << endl;
                    return 0;
                }
                ans[have.top()] = id;
                have.pop();
                pre = id;
            } else {
                cout << "NO" << endl;
                return 0;
            }

            q.push(*s.begin());
            s.erase(s.begin());
        }
    }

    int now = 1;

    s.clear();

    for (int i = 1; i <= 2 * n; i++) {
        if (qu[i].c == '+') {
            s.insert(ans[now++]);
        } else {
            if (*s.begin() != qu[i].id) {
                cout << "NO" << endl;
                return 0;
            }
            s.erase(s.begin());
        }

    }

    cout << "YES" << endl;

    for (int i = 1; i <= n; i++) {
        if (!ans[i]) {
            ans[i] = q.top();
            q.pop();
        }
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}