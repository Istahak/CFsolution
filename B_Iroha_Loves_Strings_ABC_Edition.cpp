#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
   int n,m; cin >> n >> m;

   vector<string>v(n);

   for(auto &x:v) cin >> x;

   sort(v.begin(),v.end());
   
   for(auto x:v) cout << x;
   
   cout << '\n';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}