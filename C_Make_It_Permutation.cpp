#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{

    ll n, c, d;
    cin >> n >> c >> d;
    map<ll, ll> mp;
    ll mx = INT_MIN;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
        if (mp[x] == 1)
        {
            v.push_back(x);
        }
        mx = max(mx, x);
    }
    ll un = mp.size();
    ll cost = (n - un) * c;
    sort(v.begin(), v.end());
    if (v[0] != 1)
    {
        cost += d;
        v.push_back(1);
    }
    // cout << cost << endl;
    sort(v.begin(), v.end());
    ll sz = v.size();
    ll mi = 1e18;
    vector<ll> tem;
    for (int i = 1; i <= sz; i++)
    {
        tem.push_back(i);
    }
    if (tem == v)
    {
        cout << cost << endl;
        return;
    }
    // for (auto &x : v)
    //     cout << x << ' ';
    // cout << endl;
    ll k = 0;
    vector<pair<ll, ll>> p;
    bool ok = false;
    for (int i = sz - 1; i >= 0; i--)
    {
        ll x = (v[i] - 1 - i) * d;
        k++;
        ll y = k * c;
        // if (x == 0)
        //     break;
        if (ok)
            break;
        p.push_back({y, x});
        if (x == 0)
            ok = true;
        //cout << y << ' ' << x << endl;
    }
    ll szz = p.size();

    for (int i = 0; i < szz - 1; i++)
    {
        mi = min(mi, p[i].first + p[i + 1].second);
    }
    // cout<<mi<<endl;
    mi = min(mi, p[0].second);
    mi=min(mi,p.back().first);
    cout << cost + mi << endl;
    v.clear();
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}