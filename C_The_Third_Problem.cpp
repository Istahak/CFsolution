#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int M = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }
    int l = pos[0], r = pos[0];
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (l <= pos[i] && pos[i] <= r)
        {
            ans = ans*1ll* (r - l + 1 - i) % M;
        }
        else
        {
            l = min(l, pos[i]), r = max(r, pos[i]);
        }
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
