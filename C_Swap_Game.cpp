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
    for(auto &i:v)
    cin>>i;
    int mi=*min_element(v.begin(),v.end());
    cout<<(mi==v[0] ? "Bob":"Alice")<<endl;
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