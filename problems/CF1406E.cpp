/**
  * @Problem CF1406E.cpp
  * @Time 2020/9/13 16:14
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

ll prime[maxn];
bool vis[maxn];

int tot;


int main () {
    int n;
    cin >> n;

    ll ans = 1;
    int all = n;

    int sum = 0;

    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)  break;
        }
    }

    int k = sqrt(tot);
    int x;
    memset(vis, 0, sizeof(vis));
    int flag = 1;

    for (int i = 1; i <= tot; i++) {
        if (i >= k && ans * prime[i - k + 1] > n) break;
        cout << "B " << prime[i] << endl;
        cout.flush();
        sum = 0;
        for (int j = prime[i]; j <= n; j += prime[i]) {
            if (!vis[j]) {
                all--;
                sum++;
                vis[j] = 1;
            }
        }
        cin >> x;
        if (x != sum) {
            for (ll j = prime[i]; j <= n; j *= prime[i]) {
                cout << "A " << j << endl;
                cout.flush();
                cin >> x;
                if (x) {
                    ans *= prime[i];
                }
                else {
                    break;
                }
            }
        }

        if ((i == tot || i % k == 0) && flag) {
            cout << "A 1" << endl;
            cout.flush();
            cin >> x;
            if (x != all) {
                for (int j = i - k + 1; j <= i; j++) {
                    for (ll k = prime[j]; k <= n; k *= prime[j]) {
                        cout << "A " << k << endl;
                        cout.flush();
                        cin >> x;
                        if (x) {
                            ans *= prime[j];
                            flag = 0;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << "C " << ans << endl;




    return 0;
}

//#include<bits/stdc++.h>
//#define re register
//#define int long long
//using namespace std;
//bool vis[100002];
//int pri[100002],tot,n,x,sum,ans,ia;
//bool ha[100003];
//
//int res;
//int times = 0;
//int solve (char c, int x) {
//    times++;
////    cout << c << " " << x << endl;
//    int cnt = 0;
//    if (c == 'A') {
//        for (int i = x; i <= n; i += x) {
//            if (!ha[i]) cnt++;
//        }
//    }
//    else {
//        for (int i = x; i <= n; i += x) {
//            if (!ha[i]) {
//                cnt++;
//                if (i != res) {
//                    ha[i] = 1;
//                }
//            }
//        }
//    }
//    return cnt;
//
//}
//signed main(){
//    cin >> n >> res;
//    for(re int i=2; i<=n; ++i) {
//        if(!vis[i]) {
//            pri[++tot]=i;
//            if(i<=sqrt(n))
//                for(re int j=i*i; j<=n; j+=i)vis[j]=1;
//        }
//    }
//    memset(vis,0,sizeof(vis));
//    re int k=sqrt(tot);sum=n;ans=1;
//    cout << tot + k << endl;
//    for(re int i=1;i<=tot;++i){
//        if(i>=k&&ans*pri[i-k+1]>n)break;
//        x = solve('B', pri[i]);
//        re int num=0;
//        for(re int j=pri[i];j<=n;j+=pri[i]){
//            if(!vis[j]){
//                ++num;--sum;
//                vis[j]=1;
//            }
//        }
//        if(x!=num){
//            for(re int kk=pri[i];kk<=n;kk*=pri[i]){
//                x = solve('A', kk);
//                if(x)ans*=pri[i];
//                else break;
//            }
//        }
//        if((i==tot||i%k==0)&&!ia){
//            x = solve('A', 1);
//            if(x!=sum){
//                for(re int j=i-k+1;j<=i;++j){
//                    for(re int kk=pri[j];kk<=n;kk*=pri[j]){
//                        x = solve('A', kk);
//                        if(x)ans*=pri[j],ia=1;
//                        else break;
//                    }
//                    if(ia)break;
//                }
//            }
//        }
//    }
//    printf("C %lld",ans);cout<<endl;
//    cout << "times: " << times << endl;
//}