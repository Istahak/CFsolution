#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
//long long int a, b;
int main()
{    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     cout<<__builtin_popcount(n)<<endl;
    }
 
   return 0;
}