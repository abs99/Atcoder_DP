#include<bits/stdc++.h>
#define ll long long int
#define LOG(X)cout<<X<<endl;
#define ff first 
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;
int a[100005][3];
int dp[100005][3];
int maxpoints(int a[][3],int n){
  // intialization
  for(int i=0;i<3;i++)dp[0][i]=a[0][i];

  for(int i=1;i<n;i++){
    dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2]=a[i][2]+max(dp[i-1][0],dp[i-1][1]);
  }
  return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    int ans = maxpoints(a,n);
    cout << ans;
 return 0;

}