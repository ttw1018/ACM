#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
// const int mod = 1e9 + 7;


ll a[maxn];

bool check(ll x, ll y, ll r) {
    return x * x + y * y <= r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll d, k;
        cin >> d >> k;
        ll r = (d * d) / (k * k);

        ll now = sqrt(r / 2);

        int flag;
        if (now * now + (now + 1) * (now + 1) <= r) flag = 1;
        else flag = 0;


        cout << (flag ? "Ashish" : "Utkarsh") << endl;


    }


    return 0;
}

