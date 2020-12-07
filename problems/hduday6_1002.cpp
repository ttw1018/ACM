/**
  * @Problem hduday6_1002.cpp
  * @Time 2020/8/6 12:29
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;


ll get(string s, ll b) {
    ll ans = 0;
    ll base = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        ll now;
        if (s[i] >= 'A' && s[i] <= 'F') {
            now = s[i] - 'A' + 10;
        } else {
            now = s[i] - '0';
        }
        ans += now * base;
        base = base * b;
    }
    return ans;
}

int solve(string s) {
    int a, b;
    int mi = 2;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '=') {
            b = i;
        } else if (s[i] == '+') {
            a = i;
        } else if (s[i] == '-') {
            a = i;
        } else if (s[i] == '*') {
            a = i;
        } else if (s[i] == '/') {
            a = i;
        } else {
            if (s[i] == '0') continue;
            if (s[i] >= 'A' && s[i] <= 'F') {
                mi = max(mi, s[i] - 'A' + 10 + 1);
            } else {
                mi = max(mi, s[i] - '0' + 1);
            }
        }
    }

    string s1 = s.substr(0, a);
    string s2 = s.substr(a + 1, b - a - 1);
    string s3 = s.substr(b + 1, s.length() - b - 1);

    ll n1, n2, n3;

    for (int i = mi; i <= 16; i++) {
        n1 = get(s1, i);
        n2 = get(s2, i);
        n3 = get(s3, i);
        if (s[a] == '+') {
            if (n1 + n2 == n3) return i;
        } else if (s[a] == '-') {
            if (n1 - n2 == n3) return i;
        } else if (s[a] == '*') {
            if (n1 * n2 == n3) return i;
        } else {
            if (n3 * n2 == n1) return i;
        }
    }
    return -1;
}

int main() {
    string s;
    while (cin >> s) {
        cout << solve(s) << endl;
    }


    return 0;
}
