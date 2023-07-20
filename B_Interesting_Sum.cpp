#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    ll ans=v[n-1]+v[n-2]-v[0]-v[1];
    cout<<ans<<endl;
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