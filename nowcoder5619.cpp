//
// Created by ttw on 2020/12/6.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
//const int mod = 1e9 + 7;
//const int maxn = 2e5 + 5;


int get(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}


class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k) return -1;
        map<int, int> w;
        for (auto i : nums) {
            w[i]++;
            if (w[i] > k) return -1;
        }
        if (n == k) return 0;
        sort(nums.begin(), nums.end());
        int M = (1 << n);
        int dp[M][n];
        memset(dp, 0x3f, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        int pre = n / k;
        for (int mask = 1; mask < M; mask++) {
            if (get(mask) % pre == 0) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        dp[mask][0] = min(dp[mask][0], dp[mask ^ (1 << i)][i]);
                    }
                }
                for (int pre = 1; pre < n; pre++) {
                    dp[mask][pre] = dp[mask][0];
                }
            } else {
                for (int pre = 0; pre < n; ++pre) {
                    for (int p = pre + 1; p < n; ++p) {
                        if ((mask & (1 << p)) && nums[p] > nums[pre]) {
                            dp[mask][pre] = min(dp[mask][pre], dp[mask ^ (1 << p)][p] + nums[p] - nums[pre]);
                        }
                    }
                }
            }
        }
        return dp[M - 1][0];


    }
};


int main () {
    string s;




    return 0;
}
