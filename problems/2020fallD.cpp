//#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;


class Solution {
public:
    ll c[300], a[300], inv[300];

    void init () {
        a[1] = 1;
        a[0] = 1;
        inv[1] = 1;
        inv[0] = 1;
        for (int i = 2; i < 200; i++) {
            a[i] = a[i - 1] * i % mod;
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        }
        
        for (int i = 2; i < 200; i++) {
            inv[i] = inv[i - 1] * inv[i] % mod;
        }
    }
    
    ll get (int n, int m) {
        return a[n] * inv[m] % mod * inv[n - m] % mod;
    }
    
    ll qp (ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a % mod;
            }
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }
    
    ll getinv(ll x) {
        return qp(x, mod - 2);
    }
    
    ll cnt[10];
    
    ll sum[10];
    
    ll ans = 0;
    

    void dfs (int now, int k, int n) {
        // cout << now << endl;
        if (now == k) {
            cnt[k] = n;
            sum[0] = 0;
            for (int i = 1; i < k; i++) {
                sum[i] = sum[i - 1] + cnt[i];
                cnt[k] -= i * cnt[i];

            }
            if (cnt[k] < 0 || cnt[k] % k) {
                return;
            }
            cnt[k] /= k;
            sum[k] = sum[k - 1] + cnt[k];
            if (sum[k] > 26) return;
            ll now = a[n];
            for (int i = 1; i <= k; i++) {
                now = now * get(26 - sum[i - 1], cnt[i]) % mod * getinv(qp(a[i], cnt[i])) % mod;
            }

            ans = (ans + now) % mod;
            for (int i = 1; i <= k; i++) {
                cout << cnt[i] << " ";
            }
            cout << endl;
            
            return;
        }
        
        for (int i = 0; i <= 26; i++) {
            cnt[now] = i;
            dfs(now + 1, k, n);
        }
    }
    
    ll keyboard(ll k, ll n) {
        init();
        dfs(1, k, n);
        return ans % mod ;
    }
};



int main () {
    Solution s;
    cout << s.keyboard(2, 26);

    
    

}