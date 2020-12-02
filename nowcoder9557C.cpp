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

struct edge {
    int from, to;
    edge(int a = 0, int b = 0)
        : from(a)
        , to(b)
    {
    }
} e[maxn];

int head[maxn], tot;

void add(int x, int y)
{
    e[++tot] = edge(head[x], y);
    head[x] = tot;
    e[++tot] = edge(head[y], x);
    head[y] = tot;
}

int dep[maxn];
int ma[maxn];
vector<int> v[maxn];
void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    ma[x] = dep[x];
    for (int i = head[x]; i; i = e[i].from) {
        int to = e[i].to;
        if (to == fa)
            continue;
        dfs(to, x);
        ma[x] = max(ma[x], ma[to]);
        v[x].push_back(ma[to]);
    }
}

bool cmp(int x, int y)
{
    return x > y;
}
int getmax(int n)
{
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() >= 2) {
            int now = v[i][0] + v[i][1] - 2 * dep[i];
            if (now > ans) {
                ans = now;
                cnt = 1;
                if (v[i].size() > 2 && v[i][2] == v[i][1])
                    cnt = 2;
            } else if (now == ans) {
                cnt = 2;
            }
        } else if (v[i].size() > 0) {
            int now = v[i][0] - dep[i];
            if (now > ans) {
                ans = now;
                cnt = 1;
            } else if (now == ans) {
                cnt = 2;
            }
        }
    }
    if (cnt == 2)
        return ans;
    return ans - 1;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param e int整型vector 长度为n-1的数组，表示结点2到结点n的父结点
     * @return int整型
     */

    int tree3(vector<int>& e)
    {
        // write code here
        for (int i = 0; i < e.size(); i++) {
            add(i + 2, e[i]);
        }
        dfs(1, 0);
        int n = e.size() + 1;
        int p = 0;
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (dep[i] > now) {
                now = dep[i];
                p = i;
            }
        }
        sort(dep + 1, dep + 1 + n, cmp);
        int x1 = dep[2];
        
        dfs(p, 0);

        now = 0;
        for (int i = 1; i <= n ;i++) {
            if (dep[i] > now)  {
                now = dep[i];
                p = i;
            }
        }
        sort(dep + 1, dep + 1 + n, cmp);
        int x2 = dep[2];
        
        dfs(p , 0);

        sort(dep + 1, dep + 1 + n, cmp);

        return max(dep[2], max(x1, x2)) - 1;
    }
};