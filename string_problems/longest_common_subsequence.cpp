/* Idea : longest common subsequence follows optimal substructure i.e.
Let’s consider two sequences, X and Y, of length m and n that both end in the same element. To find their LCS shorten each sequence by removing their last
element, find the LCS of their shortened sequences then append the last element into it.
      LCS(X[1…m], Y[1…n]) = LCS(X[1…m-1], Y[1…n-1]) + X[m]    if X[m] = Y[n]
Now suppose that the two sequences does not end in the same symbol.
      LCS(X[1…m], Y[1…n]) = max(LCS(X[1…m-1], Y[1…n]),LCS(X[1…m], Y[1…n-1]))
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
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    
    cout<<dp[n][m]<<endl;
}
