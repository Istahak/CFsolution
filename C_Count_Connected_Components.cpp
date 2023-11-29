#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
   int n,m; cin >> n >> m;
   vector<vector<int>>adj(n);
   vector<bool>vis(n,false);
   for(int i = 0; i < m; i++){
    int u,v; cin >> u >> v; u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   function<void(int)>dfs=[&](int v){

        vis[v] = true;

        for(auto u : adj[v]){

            if(vis[u]) continue;
            dfs(u);
        }

   };
   int ans = 0;
   for(int i = 0; i < n; i++){

        if(vis[i]==false){
            ans++;
            dfs(i);
        }

   }

   cout << ans << '\n';
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