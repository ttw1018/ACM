/**
  * @Problem nowcoder5673K.cpp
  * @Time 2020/8/3 12:10
*/

#include <bits/stdc++.h>

using namespace std;

typedef __int128 LL;

inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

const int maxn = 1e5 + 5;
LL a[maxn], b[maxn];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) a[i] = read();
        for (int i = 1; i <= n; i++) b[i] = read();
        for (int i = 2; i <= n; i++) b[i] = min(b[i], b[i - 1]);
        LL ans = b[1] * a[1];
        LL now = 0;
        for (int i = 2; i <= n; i++) {
            now += a[i];
            if (now > 0) {
                ans += now * b[i];
                now = 0;
            }
        }
        cout << "Case #" << t << ": ";
        print(b[1]);
        cout << " ";
        print(ans);
        puts("");
    }


    return 0;
}


