/*
*   FileName: CF1459A
*   Author: ttw
*   Time: 5:38 下午:2020/12/19
*/

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

//const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;


int a[maxn], b[maxn];

int main () {
    int T;
    cin >>T ;
    while (T--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i])c1++;
            else if (s1[i] < s2[i]) c2++;
        }
        if (c1 > c2) cout<< "RED" << endl;
        else if (c1 < c2) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }


    return 0;
}
