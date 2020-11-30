#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

//const int mod = 1e9 + 7
//const int mod = 998244353;

const int maxn = 1e5 + 5;

int sg[maxn];

int get(int x) {
    if (x == 1) return 0;
    int now = get(x - 1);
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int a = get(i);
            now &= a;
            if (i != x / i) {
                a = get(x / i);
                now &= a;
            }
        }
    }
    if (now == 0) return 1;
    return 0;
}


bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
void init()
{
    sg[1] = 0;
    for (int i = 2; i <= 500; i++) {
        if (get(i) == 1) {
            if (prime(i))  {
                cout << i << endl;
            }
       }
    }
}

int main()
{
    // init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int prime = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                prime = 0;
                break;
            }
        }
        if (!prime) {
            if (n == 16 || n == 34 || n == 289) {
                cout << "NIE" << endl;
            }
            else {
                cout << "TAK" << endl;
            }
        }
        else {
            if (n == 2 || n == 17) {
                cout << "TAK" << endl;
            }
            else {
                cout << "NIE" << endl;
            }
            
        }

    }

    return 0;
}