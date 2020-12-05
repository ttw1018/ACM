#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 998244353;

const int maxn = 1e5 + 5;

class Solution {
public:
    /**
     * 
     * @param k int整型 表示最多的操作次数
     * @param s string字符串 表示一个仅包含小写字母的字符串
     * @return int整型
     */
    int string2(int k, string s)
    {
        // write code here
        int ans = 1;
        int a[2000];
        for (int i = 1; i <= s.length(); i++) {
            a[i] = s[i - 1] - 'a';
        }
        int n = s.length();
        sort(a + 1, a + 1 + n);
        for (int i = 0; i < 26; i++) {
            int l = 1;
            int tmp = 0;
            for (int j = 1; j <= n; j++) {
                tmp += abs(a[j] - i);
                while (tmp > k) {
                    tmp -= abs(a[l] - i); 
                    l++;
                }
                ans = max(ans, j - l + 1);
            }
        }
        return ans;
    }
};
int main () {
    Solution test;
    cout << test.string2(10, "acesxd");
    




    return 0;
}