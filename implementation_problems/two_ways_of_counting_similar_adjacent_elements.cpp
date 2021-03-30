#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 
signed main() {
    
    int a[10] = {1,1,1,2,2,3,4,5,5,5};
    vector<pair<int,int>> vi;
    int prev = 0;
    
    // This approach is much better, we don't need to handle last set of continuous elements separately
    for(int i=0;i<10;i++) {
        while(i+1 < 10 && a[i] == a[i+1]) {
            i++;
        }
        
        vi.push_back(make_pair(a[i],i+1-prev));
        prev = i+1;
    }
    
    /*
    int i;
    for(i=1;i<10;i++) {
        if(a[i] != a[i-1]) {
            vi.push_back(make_pair(a[i-1],i-prev));
            prev = i;
        }
    }
    vi.push_back(make_pair(a[i-1],i-prev));
    */
                     
    for(auto it : vi) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    
}
