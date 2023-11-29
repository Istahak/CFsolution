#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> adj[n], vis(n, false), cnt(26, 0);
    for (int i = 0; i < n / 2; i++)
    {
        adj[i].push_back(n - i - 1);
        adj[n - i - 1].push_back(i);
    }
    for (int i = 0; i < n - k; i++)
    {
        adj[i].push_back(i + k);
        adj[i + k].push_back(i);
    }
    function<void(int)> dfs = [&](int v)
    {
        vis[v] = true;
        cnt[s[v] - 'a']++;
        for (auto u : adj[v])
        {
            if (!vis[u])
                dfs(u);
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt.assign(26, 0);
            dfs(i);
            int total = accumulate(cnt.begin(), cnt.end(), 0);
            int mx = *max_element(cnt.begin(), cnt.end());
            ans += (total - mx);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}