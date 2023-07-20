#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    while (q--)
    {
        int x;
        cin >> x;
        auto it = mp.lower_bound(x);
        if (it == mp.end())
        {
            cout << -1 << endl;
        }
        else
        {
            int ans= it->first;
            if (mp[ans] == 1)
            {
                cout << ans << endl;
                mp.erase(ans);
            }
            else
            {
                cout<<ans<<endl;
                mp[ans]--;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}