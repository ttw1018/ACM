/**
  * @Problem CF1382B.cpp
  * @Time 2020/7/21 22:41
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
int A[maxn];

#define F cout << "First" << endl;
#define S cout << "Second" << endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            if (A[i] == 1 && cnt == i) cnt++;
        }
        if (cnt == n) {
            if (cnt & 1) {
                F
            } else {
                S
            }
            continue;
        }

        if (cnt & 1) {
            S
        } else {
            F
        }

    }


    return 0;
}
