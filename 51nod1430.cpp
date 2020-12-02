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

//const int mod = 1e9 + 7
//const int mod = 998244353;

const int maxn = 1e5 + 5;

#define A                          \
    {                              \
        cout << "Stannis" << endl; \
        return 0;                  \
    }
#define B                           \
    {                               \
        cout << "Daenerys" << endl; \
        return 0;                   \
    }

int main()
{
    int n, k;
    cin >> n >> k;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a & 1)
            cnt1++;
        else
            cnt2++;
    }

    int c1 = (n - k + 1) / 2;
    int c2 = (n - k) / 2;
    if (c2 >= cnt1)
        B
    if (c1 >= cnt2 && (k & 1)) 
        A
    if (c2 >= cnt2 && !(k & 1))
        B

    if (n == k) {
        if (cnt1 & 1) A
        else B
    }
    if (c1 > c2)
        A
    else
        B
    
    return 0;
}