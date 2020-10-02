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
const int maxn = 1e5 + 5;

set<int> a, b, c;
int main() {
  int n;
  cin >> n;
  ll sum = 0;
  int cnt = 0;
  while (n--) {
    int d, tp;
    cin >> tp >> d;
    sum += d;
    if (d > 0) {
      if (tp)
        cnt++;
      else
        c.insert(d);
      if (a.size() && d > *a.rbegin()) {
        a.insert(d);
        sum += d;
      } else {
        b.insert(d);
      }

			

    } else {
    }
  }

  return 0;
}