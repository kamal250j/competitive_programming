/* 
Problem is to find if for a given range [l,r] all the elements of subarray are non-decreasing
The idea is to to store the count of indices from the starting index, having adjacent elements in increasing order i.e. a[i] > a[i+1] */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;
    cin>>n;
    int a[n];
    int pre[n] = {};
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    for(int i=0;i<n-1;i++) {
        if(a[i] <= a[i+1])
            pre[i+1] = pre[i]+1;
        else
            pre[i+1] = pre[i];
    }
    
    int l,r;
    cin>>l>>r;
    cout<<endl;
    if(pre[r] - pre[l] == r - l)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    
}
