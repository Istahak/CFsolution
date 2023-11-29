#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;
    for (auto &x : v)
        cin >> x, x %= k, mp[x]++;
    int mi = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());

    if (mi == 0)
    {
        cout << mi << "\n";
        return;
    }
    if (k == 2 or k == 3 or k == 5)
    {
        cout << k - mx << '\n';
        return;
    }
    if (k == 4)
    {
        if (mp[2] >= 2)
        {
            cout << 0 << '\n';
        }
        else if (mp[3] or (mp[2] and mp[1]))
        {
            cout << 1 << '\n';
        }
        else if (mp[1] >= 2)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 3 << '\n';
        }
        return;
    }
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