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
//const int maxn = 2e5 + 5;


void L(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> ans(n,vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = v[i][(j + 1) % n];
        }
    }
    v = ans;
}
void R(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> ans(n,vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = v[i][(j - 1 + n) % n];
        }
    }
    v = ans;
}
void U(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> ans(n,vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = v[(i + 1) % n][j];
        }
    }
    v = ans;
}
void D(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> ans(n,vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = v[(i - 1 + n) % n][j];
        }
    }
    v = ans;
}
void I(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> ans(n,vector<int>(n, 0));
    vector<int> p(n,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[v[i][j]] = j;
        }
        v[i] = p;
    }
}
void C(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> ans(n,vector<int>(n, 0));
    vector<int> p(n,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[v[j][i]] = j;
        }
        for (int j = 0; j < n; j++) {
            v[j][i] = p[j];
        }
    }
}



int main () {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                a[i][j]--;
            }
        }

        string s;
        cin >> s;


        vector<int> b(n, 0);
        for (int i = 0; i < n; i++) {
            b[i] = a[0][i];
        }

        if (n == 1) {
            cout << a[0][0] + 1 << endl;
            continue;
        }

        int flag;
        if (a[0][1] == a[1][0]) flag = 1;
        else if (a[0][0] == a[1][1]) flag = 0;
        else {
            cout << "afasdf" << endl;
            for (auto i : a) {
                for (auto j : i) {
                    cout << j + 1 << " ";
                }
                cout << endl;
            }

            cout << endl;
            exit(100000);
        }

        int line = 0;

        vector<int> tmp(n), pos(n);
        for (int i = 0; i < m; i++) {
            if (s[i] == 'U') {
                U(a);
                line = (line - 1 + n) % n;
            }
            else if (s[i] == 'D') {
                D(a);
                line = (line + 1) % n;
            }
            else if (s[i] == 'L') {
                L(a);
                for (int i = 0; i < n;i ++) {
                    tmp[i] = b[(i + 1) % n];
                }
                b = tmp;
            }
            else if (s[i] == 'R') {
                R(a);
                for (int i = 0; i < n; i++) {
                    tmp[i] = b[(i - 1 + n) % n];
                }
                b = tmp;
            }
            else if (s[i] == 'I') {
                I(a);
                for (int i = 0; i < n; i++) {
                    pos[b[i]] = i;
                }
                for (int i = 0; i < n; i++) {
                    tmp[b[(i + 1) % n]] = i;
                }
                b = pos;
                if (pos[1] != tmp[0]) flag ^= 1;
            }
            else {
                C(a);
                vector<int> c(n, 0);
                if (flag) {
                    for (int i = 0; i < n; i++) {
                        tmp[(i + line) % n] = b[i];
                    }
                    for (int i = 0; i < n; i++) {
                        pos[tmp[i]] = i;
                    }
                    for (int i = 0; i < n; i++) {
                        c[tmp[(i + 1) % n]] = i;
                    }
                    tmp = pos;
                }
                else {
                    for (int i = 0; i < n; i++) {
                        tmp[(line - i + n) % n] = b[i];
                    }
                    for (int i = 0; i < n; i++) {
                        pos[tmp[i]] = i;
                    }
                    for (int i = 0; i < n; i++) {
                        c[tmp[(i - 1 + n) % n]] = i;
                    }
                    tmp = pos;
                }
                if (c[line] == pos[(line - 1 + n) % n]) flag = 0;
                else if (c[line] == pos[(line + 1) % n]) flag = 1;
                else {
//                    cout << "D" << endl;
                }

                if (flag) {
                    for (int i = 0; i < n; i++) {
                        b[i] = tmp[(i + line) % n];
                    }
                }
                else {
                    for (int i = 0; i < n;i ++) {
                        b[i] = tmp[(line - i + n) % n];
                    }
                }
            }
//            for (int i = 0; i < n; i++) {
//                if (b[i] != a[line][i])  {
//                    cout << i << " " << s[i] << " " << "wrong answer" << endl;
//                    cout << s << endl;
//                    exit(0);
//
//                }
//            }
//            cout << line << " " << flag <<  endl;
//            for (auto i : b) {
//                cout << i << " ";
//            }
//            cout << endl;
//            cout << endl;
//            for (auto i : a) {
//                for (auto j : i) {
//                    cout << j << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
//
//            cout << "-------------------------------"<<endl;
        }
        for (auto i : a) {
            for (auto j : i) {
                cout << j + 1 << " ";
            }
            cout << endl;
        }

        cout << endl;
        continue;


        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            ans[line][i] = b[i];
        }

        if (flag) {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans[(line + i) % n][j] = ans[(line + i - 1) % n][(j + 1) % n];
                }
            }

        }
        else {
            for (int i = 1; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    ans[(line - i + n) % n][j] = ans[(line - i + 1 + n) % n][(j + 1) % n];
                }
            }
        }
        for (auto i : ans) {
            for (auto j : i) {
                cout << j + 1 << " ";
            }
            cout << endl;
        }



    }

    return 0;
}
