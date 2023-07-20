#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int x = 0;
    int ans = 0;
    vector<int> prefix(n, 0);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] ^ v[i];
        ans = max(ans, prefix[i]);
    }
    vector<int> suffix(n, 0);
    suffix[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] ^ v[i];
        ans = max(ans, suffix[i]);
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