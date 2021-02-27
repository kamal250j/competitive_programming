/* The idea is to store to keep of map sum and the lowest index where it was achieved. After that for sum achieved at
   every index, subtract sum - s and check if this element exists in map and maximize this length using maxi variable */

#include<bits/stdc++.h>
//#define int long long
using namespace std;
signed main() {
    
    int n,s;
    cin>>n>>s;
    int a[n];
    int sum = 0;
    map<int,int> mp;
    
    int maxi = 0;
    mp.clear();
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
        
        // Here cannot use if(mp[sum] != 0) becuase if sum is not present then mp[sum] has undefined behaviour
        // Use this mp[element] if and only if you are sure element will be present in map
        if(mp.find(sum) == mp.end()) 
            mp[sum] = i;
        if(mp.find(sum-s) != mp.end() && (i - mp[sum-s] > maxi))
           maxi = i - mp[sum-s];
        
    }
    
    for(map<int,int>::iterator it = mp.begin(); it != mp.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
           
    cout<<maxi<<endl;
}