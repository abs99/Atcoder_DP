#include<bits/stdc++.h>
#define ll long long int
#define LOG(X)cout<<X<<endl;
#define ff first 
#define ss second
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define F(i,l,r) for(int i=l;i<r;i++)
#define R(i,l,r) for(int i=r;i>l;i--)
#define FL(i,l,r) for(int i=l;i<=r;i++)
#define RL(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
ll dfs(vector<vector<int> >&adj,int u,ll* dp){
 
  ll maxl=0;
  if(dp[u]!=-1)return dp[u];
  for(int i=0;i<adj[u].size();i++){
    ll l=0,v=adj[u][i];
    l=dfs(adj,v,dp)+1;
    maxl=max(maxl,l);
  }
  return dp[u]=maxl;
}
ll solve( vector<vector<int> >&adj,int n){
  ll dp[n+1];
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++){
      dfs(adj,i,dp);
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    //cout << dp[i]<<' ';
    ans=max(ans,dp[i]);
  }
  return ans;
}
int main()
{
    ll n,e;
    cin>>n>>e;
    vector<pair<int,int> >edges;
    F(i,0,e){
      int u,v;
      cin>>u>>v;
      edges.push_back({u,v});
    }
    vector<vector<int> >adj(n+1);
    for(auto ed:edges){
      adj[ed.ff].push_back(ed.ss);
    }
    ll ans=solve(adj,n);
    cout<<ans;
 return 0;
}