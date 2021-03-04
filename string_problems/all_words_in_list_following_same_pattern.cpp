/*
Input:
list = [leet, abcd, loot, geek, cool, for, peer, dear, seed, meet, noon, otto, mess, loss]
 
pattern = moon (pattern is 4 digits with distinct character at first and last index, 
and same character at 1st and 2nd index)
 
Output: [leet, loot, geek, cool, peer, seed, meet]
*/

#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 
signed main() {
    
    int n;
    cin>>n;
    vector<string> vs(n);
    unordered_map<char,char> um;
    unordered_set<char> us;
    for(int i=0;i<n;i++) {
        cin>>vs[i];
    }
    string p;
    cin>>p;
    
    bool flag = false;
    for(int i=0;i<n;i++) {
        flag = false;
        um.clear();
        us.clear();
        for(int j=0;j<vs[i].length();j++) {
            if(vs[i].length() != p.length()){
                flag = true;
                break;
            }
            if(um.find(vs[i][j]) != um.end() && um[vs[i][j]] != p[j]) {
                flag = true;
                break;
            }
            else if(um.find(vs[i][j]) == um.end() && us.find(p[j]) != us.end()) {
                flag = true;
                break;
            }
            else {
                um.insert(make_pair(vs[i][j],p[j]));
                us.insert(p[j]);
            }
        }
        if(flag == false) {
            cout<<vs[i]<<" ";
        }
    }
}