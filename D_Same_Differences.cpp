#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    map<int, ll> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x - i]++;
    }
    ll ans = 0;
    for (auto i : mp)
    {
        ans += ((i.second * (i.second - 1)) / 2);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
