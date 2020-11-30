#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
// const int mod = 1e9 + 7;

char a[maxn], b[maxn];
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cin >> (a + 1);
        cin >> (b + 1);
        int cnt[2][30];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cnt[0][a[i] - 'a']++;
            cnt[1][b[i] - 'a']++;
        }
        int flag = 1;
        for (int i = 0; i < 26; i++) {
            if (cnt[0][i] >= cnt[1][i]) {
                int all = cnt[0][i] - cnt[1][i];
                if (all % k == 0) {
                    cnt[0][i + 1] += all;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "YES" : "NO")  << endl;
    }
    



    return 0;
}

