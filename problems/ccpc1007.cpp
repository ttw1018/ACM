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

char s[maxn];


int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        int cnt[30];
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        int ans = 1;
        for (int i = 0; i < 26; i++) {
            ans = max(ans, cnt[i]);
        }
        printf("%d\n", ans);
    }



    return 0;
}