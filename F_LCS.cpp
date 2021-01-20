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
string lcs(string&s,string&t){
  int n=s.size(),m=t.size();
  if(!n || !m)return 0;
  int dp[n+1][[m+1]];
  string ans;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        if(i==0 || j==0){
          dp[i][j]=0;
          continue;
        }
        else if(s[i-1]==t[j-1]){
          dp[i][j]=dp[i-1][j-1]+1;
        }
        else 
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }

  int i=n,j=m;
  while(i>0 && j>0){
    if(s[i-1]==t[j-1]){
      ans+=s[i-1];
      i--;
      j--;
    }
    else if( dp[i-1][j]>dp[i][j-1])i--;
    else j--;
    
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{
  string s,t;
  cin>>s>>t;
  string res = lcs(s,t);
cout<<res;
 return 0;
}