//
// Created by ttw on 2020/11/17.
//

#include <iostream>

using namespace std;

typedef long long ll;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param n long长整型 表示标准完全二叉树的结点个数
     * @return long长整型
     */
    const int mod = 998244353;
    ll inv;

    ll qp(ll a, ll b) {
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

    ll get(ll l, ll r) {
        return (l + r) % mod * inv % mod * ((r - l + 1) % mod) % mod;
    }

    long long tree4(long long n) {
        ll ans = 0;
        ll l = 1;
        inv = qp(2, mod - 2);
        for (int i = 0;; i++) {
            ll r = l - 1 + (ll(1) << i);
//            cout << l << " " << r << endl;
            if (n >= r) {
                ans = get(l, r) * (i + 1) % mod + ans;
                ans %= mod;
                l = r + 1;
            } else {
                ans = get(l, n) * (i + 1) % mod + ans;
                ans %= mod;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution now = Solution();
    cout << now.tree4(2);


}

