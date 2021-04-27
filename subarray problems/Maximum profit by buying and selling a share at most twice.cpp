/* We basically need to solve this recursion dp[i,j] = max(dp[i,k] + dp[k+1,j]) for i <= k <= j 
   where dp[i,j] represents the maximum profit we get by buying and selling stock
   This can be done using segment tree as well in O(nlogn)
   Following is the approach to solve it in O(n) time and O(n) space
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],p[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    p[n-1] = 0;
    int mx = a[n-1];
    for(int i=n-2;i>=0;i--) {
        mx = max(mx,a[i]);
        p[i] = max(p[i+1],mx-a[i]);
    }
    
    int mn = a[0];
    int ans = p[0];
    for(int i=1;i<n;i++) {
        mn = min(mn,a[i]);
        ans = max(ans,a[i]-mn + p[i]);
    }
    
    cout<<ans<<endl;
}
