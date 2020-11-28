//
// Created by ttw on 2020/11/22.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;


int main () {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 7 == 0 || n % 7 == 2) {
            cout << "B" << endl;
        }
        else {
            cout << "A" << endl;
        }
    }

    return 0;
}