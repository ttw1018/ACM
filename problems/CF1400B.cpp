/**
  * @Problem CF1400B.cpp
  * @Time 2020/8/25 22:42
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;


int get(int p, int f, int cnt1, int cnt2, int s, int w) {

    cnt1 = min(cnt1, (p + f) / s);

    cnt2 = min(cnt2, (p + f - s * cnt1) / w);


    int all = cnt1 * s + cnt2 * w;

    int c1 = min(cnt1, p / s);

    p -= c1 * s;

    int c2 = p / (w - s);

    c1 -= c2;

//        cout << c1 << " " << c2 << endl;


    int now = c1 * s + c2 * w;

    cnt1 -= c1;
    cnt2 -= c2;

    int c3 = min(cnt1, f / s);
    c1 += c3;

    f -= c3 * s;

    c2 += f / w;

    return c1 + c2;

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int p, f;
        cin >> p >> f;
        int cnt1, cnt2;
        cin >> cnt1 >> cnt2;
        int s, w;
        cin >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cnt1, cnt2);
        }

        if (w == s) {
            cout << min(cnt1 + cnt2, p / s + f / s) << endl;
            continue;
        }


    }


    return 0;
}
