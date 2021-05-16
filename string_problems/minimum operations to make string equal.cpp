/* The idea is that we check from ending of string, if element is misplaced then we look for its actual position in string and add difference between the 
   positions to the answer.
   It works because when we bring an element in front it'll require all those positions which are before it in the desire string to be swapped as well.
   for eg: ADCB -> ABCD
   So, here to bring D to the last position, we will need to bring C and B in front, the order doesn't matter because we have full options of choosing which ever
   we pick first based on desired string we want. So, add 2 to the answer. Now, we have placed elements BCD in desired order.
   Now the next element in desired string is C, since we are not able to find C from the current index, it means that C is actually placed after all those elements
   so, we need to add those indices to the answer as well. here, it is 1.
   The final answer is 1 + 2 = 3;
   ADCB -> CADB -> BCAD -> ABCD
   
   Proving this that it leads to minimum number of operations, that I'll have to think.
*/
   
// code is picked directly from geeks for geeks because there is nothing much to implement, it is about getting the intuition and proving whether this is the optimized
//solution
   

#include<bits/stdc++.h>
using namespace std;
 
int minOps(string& A, string& B)
{
    int m = A.length(), n = B.length();
 
     // This parts checks whether conversion is
     // possible or not
    if (n != m)
       return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i=0; i<n; i++)   // count characters in A
       count[B[i]]++;
    for (int i=0; i<n; i++)   // subtract count for
       count[A[i]]--;         // every character in B
    for (int i=0; i<256; i++)   // Check if all counts become 0
      if (count[i])
         return -1;
 
    // This part calculates the number of operations required
    int res = 0;
    for (int i=n-1, j=n-1; i>=0; )
    {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i>=0 && A[i] != B[j])
        {
            i--;
            res++;
        }
 
        // If A[i] and B[j] match
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
}
 
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations "
            "required is " << minOps(A, B);
    return 0;
}
