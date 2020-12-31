/**
  * @Problem C.cpp.c
  * @Time 2020/12/31 21:28
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

bool vis[maxn];

int prime[maxn], cnt;
bool ha[maxn];

void find() {
    for (int i = 2; i < maxn; i++) {
        if (!ha[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            ha[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    find();
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            flag = 1;
        }
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                vis[i] = vis[a / i] = 1;
            }
        }

    }
    if (!flag) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < cnt; i++) {
        if (!vis[prime[i]]) {
            cout << prime[i] << endl;
            return 0;
        }
    }


    return 0;
}
