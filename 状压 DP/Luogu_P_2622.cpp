//P2622 关灯问题 II
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int n,m,a[1000005],f[1500000],sum[1000005][35],num[35];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		num[a[i]]++;
		for(int j=1; j<=m; j++) sum[i][j]=sum[i-1][j];
		sum[i][a[i]]++;
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=0; i<(1<<m); i++) {
		int len=0;
		for(int j=1; j<=m; j++) if(i&(1<<(j-1))) len+=num[j];
		for(int j=1; j<=m; j++) 
			if(i&(1<<(j-1))) 
				f[i]=min(f[i],f[i^(1<<(j-1))]+num[j]-(sum[len][j]-sum[len-num[j]][j]));
	}
	cout << f[(1<<m)-1];
    return 0;
}
