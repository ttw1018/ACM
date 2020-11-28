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

const int maxn = 1e5;
int ans[maxn];

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回最大和的字符串
     * @param x string字符串 即题目描述中所给字符串
     * @param k int整型 即题目描述中所给的k
     * @return string字符串
     */
    string Maxsumforknumers(string x, int k) {
        // write code here
        vector<int> v;
        for (int i = 0; i < x.size(); i++) {
            v.push_back(x[i] - '0');
        }
        sort(v.begin(), v.end());
        for (int i = k - 1; i < v.size(); i++) {
            ans[i - k + 2] = v[i];
        }
        for (int i = 0; i < k - 1; i++) {
            ans[1] += v[i];
        }

        int len = v.size() - k + 1;
        int now = 0;
        int pos = 1;
        while (1) {
            ans[pos] += now;
            now = ans[pos] / 10;
            ans[pos] = ans[pos] % 10;
            if (now) pos++;
            else break;
        }
        pos = max(pos, len);

        string res = "";

        for (int i = pos; i >= 1; i--) {
            res += char(ans[i] + '0');
        }

        return res;
    }
};

int main () {
    Solution now = Solution();
    cout << now.Maxsumforknumers("345", 2) << endl;
    cout << now.Maxsumforknumers("233333", 3);


    return 0;
}
