/* 
Problem Statement GFG :
Given an array, arr[] representing a permutation of first N natural numbers in the range [1, N], the task for each every ith index is to check 
if an i-length subarray exists or not such that it contains all the numbers in the range [1, i]. 
Note: 1 – based indexing used.

Input: arr[] = {4, 5, 1, 3, 2}
Output: True False True False True
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        mp[a[i]] = i; // remember map will keep value sorted
    }
    
    /* Here we need to sort with indices and then check all elements are adjacent
       using the condition if max - min + 1 == it -> first */
    
    map<int,int>::iterator it = mp.begin();
    cout<<"true"<<" ";
    int maxi = it->second;
    int mini = it->second;
    it++;
    for(;it != mp.end();it++) {
        maxi = max(maxi,it->second);
        mini = min(mini,it->second);
        if(maxi - mini + 1 == it->first)
            cout<<"true"<<" ";
        else
            cout<<"false"<<" ";
    }
    
}
