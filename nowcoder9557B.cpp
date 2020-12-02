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
     * 给定一个后缀表达式，返回它的结果
     * @param str string字符串 
     * @return long长整型
     */
    long long solve(string s)
    {
        // write code here
        //

        stack<ll> st;
        ll now = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                st.push(now);
                now = 0;
            } else if (s[i] >= '0' && s[i] <= '9') {
                now = now * 10 + s[i] - '0';
            } else {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                if (s[i] == '+')
                    st.push(a + b);
                else if (s[i] == '-')
                    st.push(a - b);
                else
                    st.push(a * b);
            }
        }
        return st.top();
    }
};

int main () {

    return 0;
}