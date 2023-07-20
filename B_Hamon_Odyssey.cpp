#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int mn = v[0];
    for (int i = 1; i < n; i++)
    {
        mn = min(mn, mn & v[i]);
    }
    if (mn)
    {
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    int sc = v[0];
    for (int i = 1; i < n; i++)
    {

        if (sc == mn)
        {

            ans++;
            sc = v[i];
        }
        else
            sc &= v[i];
    }
    if (sc == mn)
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