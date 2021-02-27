/* multimap is similar but can store duplicate keys as well unlike map */

#include<bits/stdc++.h>
//#define int long long
using namespace std;
signed main() {
    
    string s = "abcdbacdej";
    multimap<char,int> mm;
    for(int i=0;i<s.length();i++) {
        mm.insert(make_pair(s[i],i));
    }
    
    // mm[s[i]] = i will not work here
    
    for(multimap<char,int>::iterator it = mm.begin(); it != mm.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}