/* Point to note is comparing two unorderd maps using == operator */

#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 
 
signed main() {
    
    string s1,s2;
    cin>>s1>>s2;
    unordered_map<char,int> um1,um2;
    for(int i=0;i<s1.length();i++) um1[s1[i]]++;
    for(int i=0;i<s2.length();i++) um2[s2[i]]++;
    if(um1 == um2) 
        cout<<"anagram"<<endl;
    else
        cout<<"not anagram"<<endl;
}
