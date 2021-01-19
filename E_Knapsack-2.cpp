#include<bits/stdc++.h>
#define ll long long int
#define LOG(X)cout<<X<<endl;
#define ff first 
#define ss second
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define F(i,l,r) for(int i=l;i<r;i++)
#define R(i,l,r) for(int i=r;i>=l;i--)
using namespace std; 

ll knapsack(ll W,ll *w,ll *v,ll n){
  ll t=0;
  F(i,0,n){
   t+=v[i];
  }
  vector<vll> dp(n+1,vll(t+1,INT_MAX));
  F(i,0,n+1)dp[i][0]=0;

  F(i,1,n+1){
    F(j,1,t+1){
      if(v[i-1]<=j){
        dp[i][j]=min(w[i-1]+dp[i-1][j-v[i-1]],dp[i-1][j]);
      }
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  ll ans=0;
  for(int i=t;i>=0;i--){
    if(dp[n][i]<=W){
      ans=i;
      break;
    }
  }
  // F(i,0,n+1){
  //   F(j,0,t+1)cout <<dp[i][j]<<" ";
  //   cout<<endl;
  // }
  return ans;
}
int main()
{
    ll W,n;
    cin>>n>>W ;
    ll w[n],v[n];
    for(int i=0;i<n;i++)cin>>w[i]>>v[i];
    ll ans = knapsack(W,w,v,n);
  
    cout<<ans;
 return 0;
}