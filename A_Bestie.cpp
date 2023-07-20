#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int gc = 0;
    for (auto &i : v)
    {
        cin>>i;
        gc=__gcd(gc,i);
    }
    if(gc==1)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(__gcd(i+1,v[i])==1)
        {
            cout<<n-(i+1)+1<<endl;
            break;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}