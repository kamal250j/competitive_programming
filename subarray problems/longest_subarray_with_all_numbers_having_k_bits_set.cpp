/* This code print longest subarray having all k bits of number set */

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
    
    // Here if number has k bits present then added 1 in another array else 0
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
    
    // Here found the longest subarray having consecutive ones
    int cnt = 0;
    int max_cnt = 0;
    for(int i=0;i<n;i++) {
        if(b[i] == 1) {
            cnt++;
            max_cnt = max(max_cnt,cnt);
        }
        if(b[i] == 0) {
            max_cnt = max(max_cnt,cnt);
            cnt = 0;
        }
    }
    
    cout<<max_cnt<<endl; // this will give the length of maximum subarray having k bits set
}