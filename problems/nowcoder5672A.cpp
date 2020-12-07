/**
  * @Problem nowcoder5672A.cpp
  * @Time 2020/8/1 14:34
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 0x7fffffff;


int main() {
    int cnt = 0;
    for (int i = -30; i <= 30; i++) {
        for (int j = -30; j <= 30; j++) {
            if (i * i + j * j <= 900) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;


    return 0;
}
