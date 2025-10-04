//P6218 [USACO06NOV] Round Numbers S
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define eps 1e-6
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int l,r,dp[150][150],bin[150];
void init() {
    for(int i=0; i<=30; i++) dp[i][0]=1;
    for(int i=1; i<=30; i++) {
        for(int j=1; j<=30; j++) {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
}
int f(int t) {
    memset(bin,0,sizeof bin);
    int x=t,len=0,zero=0,ans=0;
    while(x) {
        bin[++len]=x%2;
        x/=2;
    }
    for(int i=1; i<len-1; i++) {
        for(int j=i/2+1; j<=i; j++) {
            ans+=dp[i][j];
        }
    }
    for(int i=len-1; i>=1; i--) {
        if(!bin[i]) zero++;
        else {
            for(int j=(len+1)/2-(zero+1); j<=i; j++) {
                ans+=dp[i-1][j];
            }
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;
    init();
    cout << f(r+1)-f(l);
    return 0;
}