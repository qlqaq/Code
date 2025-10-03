//P3092 [USACO13NOV] No Change G
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int k,n,dp[1500000],s[20],sum[100005],a[100005],maxn=-1;
bool check(int l,int r,int k) {
	//l：左侧 r:右侧 k:钱数 
	return k>=sum[r]-sum[l];
}
int f(int x,int k) {
	int l=0,r=n-x;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(x,x+mid,k)) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int l(int x) {
	int ans=0;
	for(int i=1; i<=k; i++) if(!(x&(1<<(i-1)))) ans+=s[i];
	return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> k >> n;
	for(int i=1; i<=k; i++) cin >> s[i];
	for(int i=1; i<=n; i++) cin >> a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1; i<(1<<k); i++) {
		for(int j=1; j<=k; j++) {
			//f(x,k)：寻找从x为起点，用k块钱做多能买到多少 
			if(i&(1<<(j-1))) dp[i]=max(dp[i],dp[i^(1<<(j-1))]+f(dp[i^(1<<(j-1))],s[j]));
		}
		// cout << i << " " << dp[i] << endl;
	}
	for(int i=1; i<(1<<k); i++) {
		if(dp[i]!=n) continue;
		maxn=max(maxn,l(i));
	}
	cout << maxn;
    return 0;
}

