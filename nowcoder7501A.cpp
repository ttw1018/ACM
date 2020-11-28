#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

typedef long long ll;

const int maxn = 1e7 + 5;
//const int mod = 998244353;
const int mod = 1e9 + 7;

int a[maxn];

bool vis[maxn];
int prime[maxn];
int tot;

int main () {

    int n;
    scanf("%d", &n);
    int ma = 0;
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        a[v]++;
    }
    int ans = 1;
    
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;  
        }
        for (int j = 0; j < tot && i * j < maxn; j++) {
            vis[i * prime[j]] = 1;
            a[i * prime[j]] += a[i];
            if (i % prime[j] == 0) break; 
        }
    }
    
    printf("%d\n", ans + a[1]);
    

    return 0;
}