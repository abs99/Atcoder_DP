#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define LOG(X)cout<<X<<endl;
#define ff first 
#define ss second
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define F(i,l,r) for(int i=l;i<r;i++)
#define R(i,l,r) for(int i=r;i>l;i--)
#define FL(i,l,r) for(int i=l;i<=r;i++)
#define RL(i,l,r) for(int i=r;i>=l;i--)
#define fio ios_base::sync_with_stdio(false);
using namespace std;
int main()
{  fio

  int n;
  cin>>n;
  vector<double> p(n);
  F(i,0,n)cin>>p[i];
  vector<vector<double> >dp(n+1,vector<double>(n+1,0));
  dp[0][0]=1;
  FL(i,1,n){
    FL(j,0,i){
      if(j==0)dp[i][j]=(1-p[i-1])*dp[i-1][j];
      else {
        dp[i][j]=dp[i-1][j]*(1-p[i-1])+dp[i-1][j-1]*p[i-1];
      }

    }
  }
  double ans=0.0;
  // F(i,0,n){
  //   F(j,0,n)cout<<dp[i][j]<<" " ;
  //   cout << endl;
  // }
  R(i,n/2,n){
    ans+=dp[n][i];
  }
  cout<<setprecision(10);
  cout<<ans;

 return 0;
}