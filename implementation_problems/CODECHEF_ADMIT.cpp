/* https://www.codechef.com/START1C/problems/ADMIT */

#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 
signed main() {
    
    FIO;
    int t,n,m,chef_rank,temp,k;
    int c[50004],full[50004];
    vector<pair<int,vector<int>>> vp;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>c[i];
        }
        
        vp.clear();
        vp.resize(m);
        memset(full,0,sizeof(full));
        for(int i=0;i<m;i++) {
            cin>>vp[i].first;
        }
        
        for(int i=0;i<m;i++) {
            cin>>k;
            for(int j=0;j<k;j++) {
                cin>>temp;
                vp[i].second.push_back(temp);
            }
        }
        
        chef_rank = vp[0].first;
        
        sort(vp.begin(),vp.end());
        
        int mini = n+1;
        int index;
        for(int i=0;i<m;i++) {
            mini = n+1;
            for(int j=0;j<vp[i].second.size();j++) {
                if(!full[vp[i].second[j]-1]) {
                    mini = min(mini,c[vp[i].second[j]-1]);
                    index = vp[i].second[j];
                }
            }
                full[index-1] = 1;
            if(vp[i].first == chef_rank) {
                if(mini == n+1)
                    cout<<"0"<<endl;
                else
                    cout<<index<<endl;
                break;
            }
        }
    }
}