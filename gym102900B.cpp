//
// Created by ttw on 2020/12/16.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef long long ll;


const int maxn = 1e3 + 5;
char s[maxn][maxn];
char c[maxn][maxn];

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        cin >> (c[i] + 1);
    }


    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == c[i][j]) cnt++;
        }
    }
    if (cnt * 2 >= n * m) {
        for (int i = 1; i <= n; i++) {
            cout << (s[i] + 1) << endl;
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if (s[i][j] == '.') cout << "X";
                else cout << ".";
            }
            cout << endl;
        }
    }







    return 0;
}
