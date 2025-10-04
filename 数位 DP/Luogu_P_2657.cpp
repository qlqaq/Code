//P2657 [SCOI2009] windy 数
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define eps 1e-6
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int l,r,dp[20][15],a[15];
void init() {
    for(int i=0; i<=9; i++) dp[1][i]=1;
    for(int i=2; i<=10; i++)
        for(int j=0; j<=9; j++) 
            for(int k=0; k<=9; k++) {
                if(abs(j-k)<2) continue;
                dp[i][j]+=dp[i-1][k];
            }
}
int f(int x) {
    int ans=0,len=0;
    memset(a,0,sizeof a);
    while(x) {a[++len]=x%10;x/=10;}
    for(int i=1; i<len; i++) 
        for(int j=1; j<=9; j++) 
            ans+=dp[i][j];
    for(int i=1; i<a[len]; i++) ans+=dp[len][i];
    for(int i=len-1; i>=1; i--) {
        for(int j=0; j<a[i]; j++) 
            if(abs(j-a[i+1])>=2) ans+=dp[i][j];
        if(abs(a[i+1]-a[i])<2) break;
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