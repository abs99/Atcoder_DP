#include<bits/stdc++.h>
#define ll long long int
#define LOG(X)cout<<X<<endl;
#define mod 1000000007
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
{
  fio
  ll n,m;
  cin>>n>>m;
  char a[n+1][m+1];
  ll dp[n+1][m+1];
  FL(i,1,n){                      //input
    FL(j,1,m)cin>>a[i][j];
  }

  FL(i,0,n){
    FL(j,0,m){if(i==0 || j==0)dp[i][j]=0;
      if(i==1 && j==1 )dp[i][j]=1;
      else if(a[i][j]=='.')
        dp[i][j]=dp[i-1][j]+dp[i][j-1];    // number of ways from above + number of ways from left
      else
        dp[i][j]=0;
      dp[i][j]%=mod;
    }

  }
  dp[n][m]%=mod;
  cout << dp[n][m];


 return 0;
}