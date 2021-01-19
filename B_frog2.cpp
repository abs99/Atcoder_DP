#include<bits/stdc++.h>
#define ll long long int
#define LOG(X)cout<<X<<endl;
#define ff first 
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],dp[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    //cin>>k;
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++){
      dp[i]=INT_MAX;
       for(int j=1;j<=k;j++){
         dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);
       }
    }
    cout << dp[n-1];
 return 0;
}