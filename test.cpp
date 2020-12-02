#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1e18 + 5;
const int MAXN = 1e6 + 5;
const LL MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1);
using namespace std;
LL Scan_LL() ///输入外挂
{
    LL res = 0, ch, flag = 0;
    if ((ch = getchar()) == '-')
        flag = 1;
    else if (ch >= '0' && ch <= '9')
        res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    return flag ? -res : res;
}
int Scan_Int() ///输入外挂
{
    int res = 0, ch, flag = 0;
    if ((ch = getchar()) == '-')
        flag = 1;
    else if (ch >= '0' && ch <= '9')
        res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    return flag ? -res : res;
}
void Out(LL a) ///输出外挂
{
    if (a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}
LL a[MAXN], sg[MAXN];
int main()
{
    int n;
    LL k;
    while (~scanf("%d%lld", &n, &k)) {
        LL ans = 0, tmp, ret, x;
        int j = -1;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            x = Scan_LL();
            a[i] = x;
            if (x == 1)
                continue;
            tmp = x;
            LL tp1 = x / k;
            LL tp2 = x % k;
            while (tmp) {
                if (tp2 == 0) {
                    tp1--;
                    tp2 = k;
                    sg[i] = (tp1 * (k - 1) + tp2 - 1);
                    ///cout<<"a["<<i<<"] ="<<a[i]<<endl;
                    ans ^= sg[i];
                    break;
                } else if (tp2 > 1) {
                    sg[i] = (tp1 * (k - 1) + tp2 - 1);
                    ans ^= sg[i];
                    break;
                } else {
                    tmp = (tmp - 1) / k;
                    tp1 = tmp / k;
                    tp2 = tmp % k;
                }
            }
        }
        cout << ans << endl;
        if (ans) {
            tmp = ans;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1)
                    continue;
                LL p = (tmp ^ sg[i]);
                LL q = (p - 1) / (k - 1) * k + (p - 1) % (k - 1) + 2;
                if (p == 0)
                    q = 1;
                ret = q;
                while (1) {
                    if (ret >= a[i] || ret < 0)
                        break;
                    LL tp = a[i] / k;
                    if (a[i] % k)
                        tp++;
                    if (ret >= tp) {
                        j = i;
                        goto endW;
                    }
                    ret = ret * k + 1;
                }
            }
        endW:;
            printf("Alice %d %lld\n", j, ret);
        } else
            puts("Bob");
    }
    return 0;
}