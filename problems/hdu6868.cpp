#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e7 + 5;

bool vis[maxn];
int prime[maxn], tot, mu[maxn], sum[maxn];
void init() {
	mu[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!vis[i]) {
			prime[tot++] = i;
			mu[i] = -1;
		}
		for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;

	}


	return 0;
}