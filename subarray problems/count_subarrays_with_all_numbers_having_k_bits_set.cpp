/* program counts no of subarrays in which all all numbers have k bits set */

#include<bits/stdc++.h>
//#define int long long
using namespace std;
signed main() {
    
    int n,k;
    int a[10005];
    int b[10005];
    cin>>n>>k;
    
    for(int i=0;i<n;i++) 
        cin>>a[i];
    
    int counti = 0;
    for(int i=0;i<n;i++) {
        counti = 0;
        for(int j=0;j<20;j++) {
            if(a[i] & (1 << j))
                counti++;
        }
        if(counti == k)
            b[i] = 1;
        else
            b[i] = 0;
    }
    
    int cnt = 0;
    int res = 0;
    for(int i=0;i<n;i++) {
        if(b[i] == 1) {
            cnt++;
            res += cnt;
        }
        else {
            cnt = 0;
        }
    }
    
    cout<<res<<endl; // this will give the length of maximum subarray having k bits set
}