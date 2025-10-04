#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void read(int &a){
    a=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        a=a*10+ch-'0';
        ch=getchar();
    }
    a=a*f;
}
int l,r,n1,n2,k,b;
int bin1[105];
int bin2[105];
int f[105][105];
int check(int bin[],int n){
    int s=0;
    for(int i=0;i<n-1;i++){
        s+=f[i][k-1];
    }
    k--;
    for(int i=n-1;i>=1;i--){
        if(bin[i]>1){
            s+=f[i-1][k];
            k--;
        }
    }
//    if(0==k)s++;
    return s;
}
signed main(){
    read(l),read(r),read(k),read(b);
    for(int i=0;i<=32;i++){
        f[i][0]=1;
        for(int j=1;j<=i;j++){
            f[i][j]=f[i-1][j-1]+f[i-1][j];
        }
    }
    int w=0;
    while(l){
        bin1[++n1]=l%b;
        w+=(l%b==1);
        l/=b;
    }
    while(r){
        bin2[++n2]=r%b;
        r/=b;
    }
//    cout<<check(bin1,n1)<<endl;
    cout<<check(bin2,n2)-check(bin1,n1)+(w==k)<<endl;
    return 0;
}
//1000