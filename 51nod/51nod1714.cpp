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

ll sg[70] = {
    0,
    1,
    2,
    4,
    8,
    16,
    32,
    64,
    128,
    255,
    256,
    512,
    1024,
    2048,
    3855,
    4096,
    8192,
    13107,
    16384,
    21845,
    27306,
    32768,
    38506,
    65536,
    71576,
    92115,
    101470,
    131072,
    138406,
    172589,
    240014,
    262144,
    272069,
    380556,
    524288,
    536169,
    679601,
    847140,
    1048576,
    1072054,
    1258879,
    1397519,
    2005450,
    2097152,
    2121415,
    2496892,
    2738813,
    3993667,
    4194304,
    4241896,
    4617503,
    5821704,
    7559873,
    8388608,
    8439273,
    8861366,
    11119275,
    11973252,
    13280789,
    16777216,
    16844349,
    17102035,
    19984054,
    21979742,
    23734709
};

int main()
{
    
  
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        unsigned long long a;
        cin >> a;
        int cnt = 0;
        while (a > 0) {
            if (a & 1) cnt++;
            a = a >> 1;
        }
        ans ^= sg[cnt];
    }
    if (ans) {
        cout << "B" << endl;
    }
    else {
        cout << "L" << endl; 
    }
    


    return 0;
}