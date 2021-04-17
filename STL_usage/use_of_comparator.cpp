/* Here comparator is used to store elements in sent in increasing and decreasing order of second element */
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 

struct compare {
    bool operator() (pair<int,int> f, pair<int,int> s) {
        if(f.first < s.first)
            return true;
        if(f.first == s.first && f.second > s.second)
            return true;
        return false;
    }
};

signed main() {
    
    set<pair<int,int>, compare> si;
    
    si.insert(make_pair(2,4));
    si.insert(make_pair(1,3));
    si.insert(make_pair(1,5));
    si.insert(make_pair(2,2));
    
    for(auto it : si)
        cout<<it.first<<" "<<it.second<<endl;
    
}