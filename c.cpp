#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
//long long int a, b;
void solve()
{
    ll d,k;
    cin>>d>>k;
    ll xmoves=d/k;
    ll x=xmoves*k;
    ll y=sqrt(d*d - x*x);
    ll ymoves=y/k;
    ll totalmoves=ymoves+xmoves;
    cout<<xmoves<<' '<<ymoves<<endl;
    cout<<(totalmoves&1?"Ashish":"Utkarsh")<<endl;
 
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
     
     solve();
 
    }
 
   return 0;
}   