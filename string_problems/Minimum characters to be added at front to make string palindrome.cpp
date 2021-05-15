/* O(n^2) time complexity DP approach
   The idea is to find the longest palindromic substring starting from first index, then characters to be added is s.length() - len_substr
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    cin>>A;
    
    string B = A;
    int lps[2*A.length()+1];
    memset(lps,0,sizeof(lps));
    int prev;
    string rev = A;
    reverse(rev.begin(),rev.end());
    A = A + "#" + rev;
    for(int i=1;i<A.length();i++) {
        prev = lps[i-1];
        while(prev > 0 && A[i] != A[prev]) {
            prev = lps[prev-1];
        }
        if(A[i] == A[prev]) 
            prev++;
        lps[i] = prev;
    }
    
    cout<<B.length() - lps[A.length()-1];
    
}
