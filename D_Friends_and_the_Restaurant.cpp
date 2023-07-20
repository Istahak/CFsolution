#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    for(int i=0;i<n;i++) c[i]=b[i]-a[i];
    sort(c.begin(),c.end());
    //sort(b.begin(),b.end());
    int ans=0;
    int l=0,r=n-1;
    while(l<r)
    {
        if(c[l]+c[r]>=0)
        {
            ans++;
            r--;
        }
        l++;
    }
    cout<<ans<<endl;


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
