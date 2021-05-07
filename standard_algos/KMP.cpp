#include <bits/stdc++.h>
using namespace std;

int lps[1003];
/* method calculates the length of the longest prefix which is also a suffix for
   for every index and stores in lps array */
void createLpsArray(string pat) {
    
    int prev;
    for(int i=1;i<pat.length();i++) {
        prev = lps[i-1];
        while(prev > 0 && pat[i] != pat[prev]) {
            prev = lps[prev-1];
        }
        if(pat[i] == pat[prev])
            prev++;
        lps[i] = prev;
    }
}
    

int main()
{
    string s;
    string pat;
    cin>>s>>pat;
    createLpsArray(pat);
    
    bool flag = false;
    for(int i=0,j = 0;i<s.length();) {
        if(s[i] == pat[j]) {
            i++; j++;
            
            if(j == pat.length()) {
                flag = true;
                cout<<"pattern found at "<<i-j<<endl;
                j = lps[j-1];
            }
            
        }
        else if(i < s.length() && s[i] != pat[j]) {
            j != 0 ? j = lps[j-1] : i++;
        }
    }
    
    if(flag == false)
        cout<<"Pattern not found"<<endl;
}
