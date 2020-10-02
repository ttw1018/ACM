#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

//const int mod = 998244353;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

map<int, string> hsh;

string get (int n) {
    bool s[8];
    memset(s, 0, sizeof(s));
    for (int i = 7; i >= 0; i--, n /= 2) {
        if (n & 1) {
            s[i] = 1;
        }
    }
    string ans = "";
    for (int i = 0; i < 8; i++) {
        if (s[i]) {
            ans += "1";
        }
        else {
            ans += "0";
        }
    }
    return ans;
}

struct IP {
    char s[30];
    int len;
    
    string ss;
    
    void get () {
        int now = 0;
        int n[5];
        int tot = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] != '.' && s[i] != '/')  {
                now = now * 10 + (s[i] - '0');
            }
            else {
                n[tot++] = now;
                now = 0;
            }
        }
        len = now;
        string ans = "";
        
        for (int i = 0; i < 4; i++)
            ans += hsh[n[i]];
        ss = ans.substr(0, len);
        
    }

    bool operator < (IP i) {
        return len < i.len;
    }

} ip[maxn];




int t[maxn][30];
int has[maxn * 30];

map<IP, int> w;
int tot = 0;

void insert (string s, IP ip) {
    int now = 0;
    for (int i = 0; i < ip.len; i++) {
        int v = (s[i] == '1');
        if (!t[now][v]) {
            t[now][v] = ++tot;
        }
        now = t[now][v];
        if (i < s.length() - 1 && has[now] == 1) {
            return;
        }
        if (i == s.length() - 1) {
            has[now] = 1;
            printf("%s\n", ip.s);
        }
    }
}


int main () {

    for (int i = 0; i < 256; i++) {
        hsh[i] = get(i);
    }
    string s;
    
    int pos = -1;
    while (scanf("%s", ip[++pos].s) != EOF) {
        ip[pos].get();
    }
    
    sort(ip, ip + pos);

    
    for (int i = 0; i < pos; i++) {
        insert(ip[i].ss, ip[i]);
    }

    return 0;
}