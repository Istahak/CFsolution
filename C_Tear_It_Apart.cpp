#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
ll dp[N];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    map<int, vector<int>> v;
    for (int i = 0; i < 26; i++)
        v[i].push_back(-1);
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++)
        v[i].push_back(n);
    ll best = dp[n];
    for (auto [i, v] : v)
    {
        ll cur = 0;
        for (int i = 1; i < (int)v.size(); i++)
        {
            cur = max(cur, dp[v[i] - v[i - 1] - 1]);
        }
        best = min(best, cur);
    }
    cout << best << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i < N; i++)
        dp[i] = 1 + dp[i >> 1];
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}