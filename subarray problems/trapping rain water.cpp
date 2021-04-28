/* https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1# */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int mx_left[n],mx_right[n];
    mx_left[0] = a[0];
    for(int i=1;i<n;i++) {
        mx_left[i] = max(mx_left[i-1],a[i]);
    }

    mx_right[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--) {
        mx_right[i] = max(mx_right[i+1],a[i]);
    }

    long long ans = 0;
    for(int i=0;i<n;i++) {
        ans += (long long) max(0,min(mx_left[i],mx_right[i])-a[i]);
    }

    cout<<ans;
}
