#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    
    vector<int>v(11,0);
    for(int i = 0; i < 3; i++){
        int x; cin >> x;
        v[x]++;
    }
    cout << ((v[5] == 2 and v[7] == 1) ? "YES" : "NO" ) <<'\n';

   
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