#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*d==b*c){cout<<0<<endl;return;}
    //ll f1=a*d,f2
    if((a!=0 && d!=0)&&((b*c)%(a*d)==0)||(b!=0 && c!=0)&&((a*d)%(b*c)==0))
    {
        cout<<1<<endl;return;
    }
    cout<<2<<endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin>>t;
    while (t--)
    {

        solve();
    }

    return 0;
}