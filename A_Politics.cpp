#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[0] == v[i])
            ans++;
    }
    ans++;
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