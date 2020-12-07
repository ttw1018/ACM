/**
  * @Problem nowcoder5672I.cpp
  * @Time 2020/8/1 15:06
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
const int inf = 0x7fffffff;

ll mod;
ll dp[5005][10005];

void init() {
    dp[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        for (int j = 2 * i - 2; j >= 1; j--) {
            if (dp[i - 1][])
        }
    }


}


int main() {
    init();


    return 0;
}
