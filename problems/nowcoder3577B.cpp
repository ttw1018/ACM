/**
  * @Problem nowcoder3577B.cpp
  * @Time 2020/7/18 9:57
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int A[100];
int res = 0;

void merge(int *a, int len) {
    int ans[100];
    int l = len / 2;
    int r = len - l;
    int i = 0, j = 0;
    int cnt = 0;
    while (i < l && j < r) {
        res++;
        if (a[i] < a[l + j]) {
            ans[++cnt] = a[i++];
        } else if (a[i] == a[l + i]) {
            ans[++cnt] = a[i++];
            ans[++cnt] = a[j++];
        } else {
            ans[++cnt] = a[j++];
        }
    }
    while (i < l) {
        ans[++cnt] = a[i++];
    }
    while (j < r) {
        ans[++cnt] = a[j++];
    }

    for (int i = 0; i < len; i++) {
        a[i] = ans[i + 1];
    }
}


void mergesort(int *A, int len) {
    if (len == 1) return;
    int mid = len / 2;
    mergesort(A, mid);
    mergesort(A + mid, len - mid);
    merge(A, len);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    mergesort(A + 1, n);
    cout << res << endl;


    return 0;
}
