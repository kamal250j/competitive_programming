/* The idea is this : first count the total number of subarrays with odd number of odd numbers starting from index 0
   Now for each element check whether the given number is even then we are going to have the same number of subarrays
   as starting from 0.
       If the number is even then we are going to have n - odd number of subarrays added
   eg :
       1 4 7 9 10
       has 4 subarrays starting from index 0 with odd count of odd numbers
       1 
       1 4
       1 4 7 9
       1 4 7 9 10
       
       Total number of subarrays possible starting from first element is 5.
       Out of these we have covered 4. And since the first element is odd, the subarray 1,2,3 will not have odd count after
       removing 1.
       
       for subarrays starting from 4, total number of subarrays possible starting from second element is 4.
       out of which we know that 3 will not have odd count. So remaining is 4 - 3 = 1
       
       for subarrays starting from 7, total number of subarrays possible starting from third element is 3.
       out of which we know that 2 will not have even count. So remaining is 3 -2 = 1
       
       This is the logic. We keep doing that and we finally get the total number of subarrays with odd count of odd numbers.
       
*/

#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int a[n];
    int odd = 0;
    int cnt = 0;
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i] % 2) odd++;
        if(odd % 2) cnt++;
    }
    
    int res = 0;
    for(int i=0;i<n;i++) {
        res += cnt;
        if(a[i] % 2) {
            cnt = n - i - cnt;
        }
    }
    cout<<res<<endl;
}
