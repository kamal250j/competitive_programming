/* LCSubstr[i][j] = LCSubstr[i-1][j-1] + 1       (if X[i-1] = Y[j-1])
                  =  0                            (otherwise)
   Here LCSubstr[i][j] represents the length of longest common substring ending at (i,j)
   So, we need to find max of of all (i,j) between (1,1) to (n,m)
*/

#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 

signed main() {
    
    int n,m;
    string s1,s2;
    cin>>n>>m;
    cin>>s1>>s2;
    
    int dp[100][100] = {};
    int maxi = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = 0;
            maxi = max(maxi,dp[i][j]);
            
        }
    }
    
    cout<<maxi<<endl;
}
