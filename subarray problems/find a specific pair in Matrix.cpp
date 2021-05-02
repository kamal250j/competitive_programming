// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
/* Coming up with solution :  
   First idea is check for each element in matrix the max element such that c > d and a > b (i.e. satisfying constraints) Time complexity : O(n^4)
   The other thing we can do is sort the whole matrix and return last - first. Time complexity : O(n^2 log n)
   If we look closely, we are iterating over the same matrix again and again, and there is also optimal substructure. So, we can find max element in 
   a matrix starting at (i,j) using elements after it. 
   dp(i,j) = max(dp(i,j+1),dp(i+1,j),a(i,j))
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m], dp[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            dp[i][j] = max(max(j+1 >= n ? INT_MIN : dp[i][j+1],i+1 >= n ? INT_MIN : dp[i+1][j]),a[i][j]);
        }
    }
    
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i < n-1 && j < n-1) 
                ans = max(ans,dp[i+1][j+1] - a[i][j]);
        }
    }
    
    cout<<ans<<endl;
}
