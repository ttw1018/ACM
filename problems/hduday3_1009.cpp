/**
  * @Problem hduday3_1009.cpp
  * @Time 2020/7/28 12:54
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

char s[maxn];
int sum[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);

        int len = strlen(s + 1);
        sum[0] = 0;
        int flag = 1;
        queue<int> q;
        for (int i = 1; i <= len; i++) {
            if (s[i] == '(') {
                sum[i] = sum[i - 1] + 1;
            } else if (s[i] == ')') {
                sum[i] = sum[i - 1] - 1;
            } else {
                q.push(i);
                sum[i] = sum[i - 1];
            }
            if (sum[i] < 0) {
                if (q.size()) {
                    int now = q.front();
                    q.pop();
                    s[now] = '(';
                    sum[i] = 0;
                } else {
                    flag = 0;
                }
            }
        }
        if (abs(sum[len]) > q.size()) {
            flag = 0;
        }
        if (!flag) {
            printf("No solution!\n");
            continue;
        }

        while (q.size() > sum[len]) {
            q.pop();
        }

        while (!q.empty()) {
            int now = q.front();
            s[now] = ')';
            q.pop();
        }

        int cnt = 0;
        vector<char> ans;

        for (int i = 1; i <= len; i++) {
            if (s[i] == '(') {
                cnt++;
                ans.push_back(s[i]);
            } else if (s[i] == ')') {
                cnt--;
                ans.push_back(s[i]);
            }
            if (cnt < 0) {
                flag = 0;
            }
        }
        if (!flag) {
            printf("No solution!\n");
            continue;
        }

        for (auto i : ans) {
            printf("%c", i);
        }
        printf("\n");


    }


    return 0;
}
