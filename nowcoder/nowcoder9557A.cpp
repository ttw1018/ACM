#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
     * 返回符合题意的最长的子串长度
     * @param x string字符串 
     * @return int整型
     */
    int Maximumlength(string s)
    {
        // write code here
        queue<int> v[3];
        int ans = 0;
        int l = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'n') {
                v[0].push(i);
                while (v[0].size() > 0 && v[1].size() > 0 && v[2].size() > 0) {
                    int a = v[0].front(), b = v[1].front(), c = v[2].front();
                    if (a <= b && a <= c) {
                        l = a;
                        v[0].pop();
                    } else if (b <= a && b <= c) {
                        l = b;
                        v[1].pop();
                    } else if (c <= a && c <= b) {
                        v[2].pop();
                        l = c;
                    }
                    while (v[0].size() && v[0].front() <= l)
                        v[0].pop();
                    while (v[1].size() && v[1].front() <= l)
                        v[1].pop();
                    while (v[2].size() && v[2].front() <= l)
                        v[2].pop();
                }
                ans = max(ans, i - l);
            } else if (s[i] == 'p') {
                v[1].push(i);
                while (v[0].size() > 0 && v[1].size() > 0 && v[2].size() > 0) {
                    int a = v[0].front(), b = v[1].front(), c = v[2].front();
                    if (a <= b && a <= c) {
                        l = a;
                        v[0].pop();
                    } else if (b <= a && b <= c) {
                        l = b;
                        v[1].pop();
                    } else if (c <= a && c <= b) {
                        l = c;
                        v[2].pop();
                    }
                    while (v[0].size() && v[0].front() <= l)
                        v[0].pop();
                    while (v[1].size() && v[1].front() <= l)
                        v[1].pop();
                    while (v[2].size() && v[2].front() <= l)
                        v[2].pop();
                }
                ans = max(ans, i - l);
            } else if (s[i] == 'y') {
                v[2].push(i);
                while (v[0].size() > 0 && v[1].size() > 0 && v[2].size() > 0) {
                    int a = v[0].front(), b = v[1].front(), c = v[2].front();
                    if (a <= b && a <= c) {
                        l = a;
                        v[0].pop();
                    } else if (b <= a && b <= c) {
                        l = b;
                        v[1].pop();
                    } else if (c <= a && c <= b) {
                        v[2].pop();
                        l = c;
                    }
                    while (v[0].size() && v[0].front() <= l)
                        v[0].pop();
                    while (v[1].size() && v[1].front() <= l)
                        v[1].pop();
                    while (v[2].size() && v[2].front() <= l)
                        v[2].pop();
                }
                ans = max(ans, i - l);
            }
            ans = max(ans, i - l);
            cout << i << " " << l << " " << ans << endl;
        }
        ans = max(ans, int(s.length() - l - 1));
        return ans;
    }
};

int main()
{
    Solution test;
    cout << test.Maximumlength("ypknnbpiyc");

    return 0;
}