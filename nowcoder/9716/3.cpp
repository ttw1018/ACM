#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 1e5 + 5;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @return long长整型
     */
    long long Sum(int n)
    {
        ll sum = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = n / (n / l);
            cout << l << " "<< r << endl;
            int ll = l, rr = r;
            if (n % l == 0) {
                ll++;
                sum += n / l;
            }
            if (n % r == 0 && l != r) {
                sum += n / r;
                rr--;
            }
            if (ll <= rr) {
                sum += (rr - ll + 1) * (n / ll + 1);
            }
            cout << sum << endl;
        }
        return sum;
    }
};
// int main()
// {
//     Solution test;
//     cout << test.Sum(10);

//     return 0;
// }