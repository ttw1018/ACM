/**
  * @Problem nowcoder5667J.cpp
  * @Time 2020/7/13 14:27
*/



#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;


const int maxn = 1e5 + 5;

int A[maxn];

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gc = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return gc;
}


int getinv(int a, int b) {
    int x, y;
    int gc = exgcd(a, b, x, y);
    if (gc != 1) return -1;
    x = (x % b + b) % b;
    return x;
}

int vis[maxn];

int ans[maxn];


void test() {
    int x, y;
    exgcd(3, 4, x, y);
    cout << x << " " << y << endl;
}

int main() {
//    test();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> v;
            int start = i;
            do {
                v.push_back(start);
                vis[start] = 1;
                start = A[start];
            } while (!vis[start]);

            int siz = v.size();
            int times = getinv(k % siz, siz);
            for (int j = 0; j < siz; j++) {
                ans[v[j]] = v[(j + times) % siz];
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}


