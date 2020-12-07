/**
  * @Problem nowcoder5668F.cpp
  * @Time 2020/7/18 15:03
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

ll c, d, e, f;


ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll gc = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return gc;
}


bool solve(ll a, ll b, ll all) {
    ll x, y;
    ll gc = exgcd(a, b, x, y);

    if (all % gc) {
        return false;
    }


    y = -y;
    if (x < 0) {
        y += (x / (b / gc) + 1) * (a / gc);
        x += (x / (b / gc) + 1) * (b / gc);
    }
    if (y < 0) {
        x += (y / (a / gc) + 1) * (b / gc);
        y += (y / (a / gc) + 1) * (a / gc);
    }

    c = x * all / gc;
    e = y * all / gc;
    d = b, f = a;


    return true;
}

const int maxn = 2e6 + 5;
int prime[maxn], vis[maxn];
int tot = 0;
vector<int> num[maxn];

void getprime() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }

    }
}


int main() {
    getprime();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        int gcdab = gcd(a, b);
        if (gcdab != 1) {
            printf("%d %d 1 1\n", (a + b) / gcdab, b / gcdab);
            continue;
        }
        c = -1, d = -1, e = -1, f = -1;
        ll temp = b;
        ll A = 1, B = 1;
        for (int i = 1; i <= tot && temp >= prime[i]; i++) {
            if (temp % prime[i] == 0) {
                while (temp % prime[i] == 0) {
                    A *= prime[i];
                    temp /= prime[i];
                }
                B = temp;
                break;
            }
        }
        if (A == 1 || B == 1) {
            printf("%lld %lld %lld %lld\n", c, d, e, f);
            continue;
        }
        solve(A, B, a);
        printf("%lld %lld %lld %lld\n", c, d, e, f);


    }


    return 0;
}


