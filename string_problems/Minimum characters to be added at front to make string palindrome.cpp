/* O(n^2) time complexity DP approach
   The idea is to find the longest palindromic substring starting from first index, then characters to be added is s.length() - len_substr
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int dp[s.length()][s.length()];
    int len = s.length();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<s.length();i++) {
        dp[i][i] = 1;
        dp[i][min(i+1,len-1)] = (s[i] == s[i+1]) ? 1 : 0;
    }
    
    int l = 0, r = 0;
    for(int i=0;i<s.length();i++) {
        l = i; r = i;
        while(l >= 0 && r < s.length()) {
            if(s[l] == s[r]) {
                dp[l][r] = 1;
            }
            else
                break;
            l--; r++;
        }
    }
    
    for(int i=0;i+1<s.length();i++) {
        l = i; r = i+1;
        while(l >= 0 && r < s.length()) {
            if(s[l] == s[r]) {
                dp[l][r] = 1;
            }
            else
                break;
            l--; r++;
        }
    }
    
    int mn = 0;
    int ans = -1;
    for(int j=0;j<s.length();j++) {
        if(dp[0][j] && mn < j+1) {
            mn = j+1;
            ans = s.length()-j-1;
        }
    }
    
    cout<<ans<<endl;
    
}
