/* https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/
   space not considered in this solution but its simple */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char,pair<int,int>> um;
    string arr[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    for(int i=0;i<8;i++) {
        for(int j=0;j<arr[i].length();j++) {
            um.insert(make_pair(arr[i][j],make_pair(i+2,j+1)));
        }
    }
    
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++) {
        for(int j=0;j<um[s[i]].second;j++) {
            cout<<um[s[i]].first;
        }
    }
    
}
