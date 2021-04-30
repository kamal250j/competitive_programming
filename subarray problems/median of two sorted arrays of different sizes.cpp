#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int j=0;j<m;j++) {
        cin>>b[j];
    }
    
    int l = 0, r = n;
    double ans;
    while(l <= r) {
        int px = l + (r - l) / 2;
        int py = (n + m + 1) / 2  - px;
        int lx = (px == 0 ? INT_MIN : a[px-1]); // these conditions are to handle edge cases when all elements in one
        int rx = (px == n ? INT_MAX : a[px]);   // array is greater or lesser than every elements in other array
        int ly = (py == 0 ? INT_MIN : b[py-1]);
        int ry = (py == n ? INT_MAX : b[py]);
        if(lx <= ry && ly <= rx) { 
            if((m + n) % 2)                                                       
                ans = max(lx,ly);                                                    
            else
                ans = (double) (max(lx,ly) + min(rx,ry)) / 2;
            break;
        }
        else if(lx > ry) {
            r = px - 1;
        }
        else if(ly > rx) {
            l = px + 1;
        }
    }
    cout<<ans<<endl;
}
