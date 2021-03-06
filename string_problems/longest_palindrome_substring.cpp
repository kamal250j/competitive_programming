/* Idea : fill the table diagonally towards the top right of table 
  eg : (0,0) (1,1) (2,2) (3,3) (0,1) (1,2) (2,3) (0,2) (1,3) (0,3)
  (i,j) gives whether palindrome exists between index i to j (both inclusive) of string 
*/

// this problem can be solved in O(n^2) time without using space. Also, this can be solved in O(n) time using Manacher's algorithm 

#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ; 

signed main() {
    
    string a;
    cin>>a;
    int n = a.length();
    
    bool dp[50][50] = {};
    
    int ans = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;i+j<n;j++) {
            if(j == i+j) 
                dp[j][i+j] = true;
            else if(j == i+j-1 && a[j] == a[i+j])
                dp[j][i+j] = true;
            else if(a[j] == a[i+j])
                dp[j][i+j] = dp[j+1][i+j-1] == true ? true : false;
            ans = dp[j][i+j] == true ? max(ans,i+1) : ans;
        }
    }
    cout<<ans<<endl;
    
}
