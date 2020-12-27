#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7;
const int mod = 998244353;

const int maxn = 1e5 + 5;


int a[maxn], b[maxn];

int gcd (int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main () {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k * k <= i; k++) {
      if (i % k == 0) {
        
      }
      
    }
    
  }
  for (int i = 1; i < 100000; i++) {
    cout << gcd (i, 100000) << endl;
  }
  
  cout << (1 << 14) - 2 << endl;
  cout << (1 << 21) - 2 << endl;
  cout << pow(ll(2), 21) - 2 << endl;
  
  while (1) {
    cout << "hello world" << endl;
  }
  
  
  




  return 0;
}