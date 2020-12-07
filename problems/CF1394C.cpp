/**
  * @Problem CF1394C.cpp
  * @Time 2020/8/14 14:06
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 3e5 + 5;
pair<int, int> A[maxn];

int n;

int l, r, u, d, a, b;

int nl, nr, nu, nd, na, nb;
int ansl, ansr;

bool check(int x) {
    nl = l, nr = r, nu = u, nd = d, na = a, nb = b;
    for (int i = 1; i <= n; i++) {
        nl = max(nl, A[i].first - x);
        nr = min(nr, A[i].first + x);
        nu = min(nu, A[i].second + x);
        nd = max(nd, A[i].second - x);
        na = max(na, A[i].second - A[i].first - x);
        nb = min(nb, A[i].second - A[i].first + x);
    }

    if (nl > nr || nd > nu || na > nb) return false;

    int y1 = nl + na;
    int y2 = nr + nb;
    if (nu < y1 || nd > y2) {
        return false;
    }
    nu = min(nu, y2);
    nd = max(nd, y1);

    if (nu - na >= nl && nu - na <= nr) {
        ansl = nu - na;
        ansr = nu;
        return true;
    }

    if (nu - nb >= nl && nu - nb <= nr) {
        ansl = nu - nb;
        ansr = nu;
        return true;
    }
    if (nd - nb >= nl && nd - nb <= nr) {
        ansl = nd - nb;
        ansr = nd;
        return true;
    }
    if (nd - na >= nl && nd - na <= nr) {
        ansl = nd - na;
        ansr = nd;
        return true;
    }


}

int main() {
    cin >> n;
    l = 500000, r = 0, d = 500000, u = 0, a = 500000, b = -500000;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'B') cnt1++;
            else cnt2++;
        }
        A[i] = make_pair(cnt1, cnt2);
        l = min(l, cnt1);
        r = max(r, cnt1);
        u = max(u, cnt2);
        d = min(d, cnt2);
        a = min(a, cnt2 - cnt1);
        b = max(b, cnt2 - cnt1);
    }

    int bl = 0, br = 500000;


    while (bl < br) {
        int mid = (bl + br) / 2;
        if (check(mid)) {
            br = mid;
        } else {
            bl = mid + 1;
        }
    }
    cout << bl << "\n";
    for (int i = 0; i < ansl; i++) cout << 'B';
    for (int i = 0; i < ansr; i++) cout << 'N';


    return 0;
}
