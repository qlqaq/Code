#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define eps 1e-6
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int l,r,dp[20][10];
void init() {
    for(int i=0; i<=9; i++) dp[1][i]=1;
    for(int i=2; i<=10; i++)
        for(int j=0; j<=9; j++) 
            for(int k=0; k<=9; k++) {
                if(abs(j-k)<=2) continue;
                dp[i][k]+=dp[i-1][j];
            }
}
int f() {
    
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;
    init();
    cout << f(r+1)-f(l);
    return 0;
}