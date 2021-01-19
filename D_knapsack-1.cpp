#include<bits/stdc++.h>
#define ll long long int
#define LOG(X)cout<<X<<endl;
#define ff first 
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;
ll dp[100005][101];
ll knapsack(ll W,ll *w,ll *v,ll n){
 // cout <<W<<" ";
   if(W<=0 || n<0)return 0;
   if(n==1)return w[0]<=W?v[0]:0;
   ll res=0;
   if(dp[W][n]!=-1)return dp[W][n];
   if(w[n-1]<=W){
       res=max(knapsack(W-w[n-1],w,v,n-1)+v[n-1],knapsack(W,w,v,n-1));
   }
   else
      res=knapsack(W,w,v,n-1);
   return dp[W][n]=res;
}
int main()
{
    ll W,n;
    cin>>n>>W ;
    ll w[n+1],v[n];
    for(int i=0;i<n;i++)cin>>w[i]>>v[i];
    memset(dp,-1,sizeof(dp));

    ll ans = knapsack(W,w,v,n);
  
    cout<<ans;
 return 0;
}