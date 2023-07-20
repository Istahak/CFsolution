#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    map<ll, int> mp;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    while (q--)
    {
        int i, x;
        cin >> i >> x;
        // cout << v[i] + x << endl;
        if (mp[v[i]])
        {
            mp[v[i]]--;
            if (mp[v[i]] == 0)
            {
                mp.erase(v[i]);
            }
        }
        // cout<<mp[v[i]]<<endl;
        v[i] += x;
        mp[v[i]]++;
        cout << mp.size() << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
