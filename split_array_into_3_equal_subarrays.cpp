/* This is used to print indices of pair of array elements required to be removed to split array into 3 equal sum subarrays */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    int pre[n] = {};
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pre[i] = pre[i-1] + a[i]; 
    }
    
    int l = 1,r = n;
    bool flag = false;
    int first, second, third;
    while(l < r) {
        first = pre[l-1] - pre[0];
        second = pre[r-1] - pre[l];
        third = pre[n] - pre[r];
        if(first > third)
            r--;
        else if(first < third) 
            l++;
        else {
            if(first == second) {
                flag = true;
                cout<<l<<" "<<r<<endl;
                break;
            }
            else {
                l++; r--;
            }
        }
    }
    if(flag == false)
        cout<<"-1"<<endl;
}
