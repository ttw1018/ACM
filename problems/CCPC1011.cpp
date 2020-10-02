#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[55][55];
int k[4][4];

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int ma = 0;
        ll sum = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                scanf("%d", &k[i][j]);
                sum += k[i][j];
            }
        }
        if (sum == k[1][1]) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%d", a[i][j]);
                    if (j == n) {
                        printf("\n");
                    }
                    else {
                        printf(" ");
                    }
                }
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("0");
                    if (j == n) {
                        printf("\n");
                    }
                    else {
                        printf(" ");
                    }
                }
            }
        }

    }

    



    return 0;
}