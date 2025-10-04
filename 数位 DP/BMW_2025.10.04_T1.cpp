#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define eps 1e-6
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int l,r,k,b,dp[40][40],bin[40];
void init() {
    for(int i=0; i<=35; i++) dp[i][0]=1;
    for(int i=1; i<=35; i++) {
        for(int j=1; j<=35; j++) {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
}
int f(int t,int kk) {
    memset(bin,0,sizeof bin);
    int x=t,len=0,ans=0;
    while(x) {
        bin[++len]=x%b;
        x/=b;
    }
    for(int i=len; i>=1; i--) {
        if(bin[i]>1) {
            ans+=dp[i][kk];
            break;
        }
        else if(bin[i]==1) {
            ans+=dp[i-1][kk];
            kk--;
        }
        if(kk<0) break;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r >> k >> b;
    init();
    cout << f(r+1,k)-f(l,k);
    return 0;
}