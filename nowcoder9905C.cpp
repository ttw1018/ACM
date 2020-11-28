//
// Created by ttw on 2020/11/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回1-n的所有k*m的和
     * @param num long长整型 正整数 n
     * @return long长整型
     */
     const int mod = 1e9 + 7;

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
    long long cowModCount(long long num) {
        // write code here
        ll ans = 0;
        ll inv2 = qp(2, mod - 2);
        for (ll r, l = 2; l <= num; l = r + 1) {
            r = num / (num / l);
            ll k = num / l;
            ll x = num % (k * l);
            ll y = num % (k * r);
//            cout << l << " " << r << endl;
            ans += k * (x + y) % mod * (r - l + 1) % mod * inv2 % mod;
            ans %= mod;
            cout << ans << endl;
        }
        return ans;
    }
};

int main () {
    Solution test = Solution();
    cout << test.cowModCount(5);



    return 0;
}