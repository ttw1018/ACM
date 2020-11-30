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

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll d, k;
        cin >> d >> k;
        ll r = (d * d) / (k * k);
        int flag = 0;
        
        for (ll i = 0; i <= sqrt(r); i++) {
            ll now = r - i * i;
            ll x = ll(sqrt(now)) + i;
            a[i] = x & 1;
        }
        ll x = 0, y = 0;
        int pos = 1;
        while (1) {
            if (pos) {
                if (a[x]) {
                    if (x * x + (y + 1) * )
                }
                else x++;
            }
            else {
                if (a[x]) x++;
                else y++;
            }
            pos ^= 1;
        }

        


        cout << (a[x] ? "Ashish" : "Utkarsh") << endl;
        

    }
    



    return 0;
}

