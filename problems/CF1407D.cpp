/**
  * @Problem CF1407D.cpp
  * @Time 2020/9/13 18:38
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;

int a[maxn];
int dp[maxn];
int l1[maxn], r1[maxn], l2[maxn], r2[maxn];

vector<int> v[maxn];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) dp[i] = n - 1;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = 0;

    stack<pair<int, int>> st;

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().second < a[i]) {
            st.pop();
        }
        if (st.size()) {
            v[st.top().first].push_back(i);
        }
        st.push(make_pair(i, a[i]));
    }


    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().second > a[i]) {
            st.pop();
        }
        if (st.size()) {
            v[st.top().first].push_back(i);
        }
        st.push(make_pair(i, a[i]));
    }

    for (int i = n; i >= 1; i--) {
        while (!st.empty() && st.top().second < a[i]) {
            st.pop();
        }
        if (st.size()) {
            v[i].push_back(st.top().first);
        }
        st.push(make_pair(i, a[i]));
    }


    for (int i = n; i >= 1; i--) {
        while (!st.empty() && st.top().second > a[i]) {
            st.pop();
        }
        if (st.size()) {
            v[i].push_back(st.top().first);
        }
        st.push(make_pair(i, a[i]));
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : v[i]) {
            dp[j] = min(dp[i] + 1, dp[j]);
        }
    }
    cout << dp[n] << endl;


    return 0;
}

