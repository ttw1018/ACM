#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define maxn 70000000
using namespace std;
typedef long long LL;

int sg[65], maxs;
int cnt[maxn];
void dfs(int j, int m, int ans, int v)
{
    if (m == 0) {
        maxs = ans > maxs ? ans : maxs;
        cnt[ans] = 1;
        return;
    }
    for (int i = v; i < j; i++) {
        dfs(j, m - 1, ans ^ sg[i], i);
    }
}
void Init()
{
    sg[0] = 0;
    for (int i = 1; i <= 5; i++) {
        for (int h = 0; h <= maxs; h++)
            cnt[h] = 0;
        maxs = 0;
        dfs(i, 7, 0, 0);
        for (int j = 0; j < maxn; j++) {
            if (cnt[j] == 0) {
                sg[i] = j;
                break;
            }
        }
        printf("%d\n", sg[i]);
    }
}
int main()
{
    Init();
}
