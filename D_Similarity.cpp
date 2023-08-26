#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x : v)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> fr(26, 0);
        for (int j = 0; j < n; j++)
        {
            fr[v[j][i] - 'a']++;
        }
        ans += *max_element(fr.begin(), fr.end());
    }
    cout << ans << endl;
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