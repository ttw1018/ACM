//
// Created by ttw on 2020/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

using namespace std;

int main () {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a % 6) cout << "October wins!" << endl;
        else cout << "Roy wins!" << endl;
    }


    return 0;
}