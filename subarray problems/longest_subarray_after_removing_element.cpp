/* This code finds the longest subarray of 1s after removing exactly one element from binary array */

#include<bits/stdc++.h>
//#define int long long
using namespace std;
signed main() {
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    int cnt = 0;
    int prev_cnt = 0;
    int max_cnt = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == 1) {
            cnt += 1;
            prev_cnt += 1;
        }
        else {
            max_cnt = max(max_cnt,prev_cnt);
            prev_cnt = cnt;
            cnt = 0;
        }
    }
    
    max_cnt = max(max_cnt,prev_cnt);    // this is for the last sequence of 1s not followed by zero
    max_cnt = max_cnt == n ? max_cnt - 1 : max_cnt; // if there is no zero present in sequence
    cout<<max_cnt<<endl;
    
}