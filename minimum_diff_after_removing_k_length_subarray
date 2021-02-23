/* This code minimizes difference between maximum and minimum array elements after removing k length subarray */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    
    int a[n+1];
    int pre_max[n+1];
    int pre_min[n+1];
    int suff_min[n+1];
    int suff_max[n+1];
    
    pre_max[0] = -11111;
    pre_min[0] = 11111;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pre_max[i] = max(pre_max[i-1],a[i]);
        pre_min[i] = min(pre_min[i-1],a[i]);
    }
    
    suff_max[n-1] = a[n];
    suff_min[n-1] = a[n];
    for(int i=n-2;i>=1;i--) {
        suff_max[i] = max(a[i+1],suff_max[i+1]);
        suff_min[i] = min(a[i+1],suff_min[i+1]);
    }

    int ans = 11111;
    for(int i=1;i<n-k+1;i++) {
        ans = min(ans,max(pre_max[i-1],suff_max[i+k-1])-min(pre_min[i-1],suff_min[i+k-1]));
    }
    
    cout<<ans<<endl;

}
    
