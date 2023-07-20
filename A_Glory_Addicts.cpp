#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> vz, vo;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (v[i])
            vo.push_back(x);
        else
            vz.push_back(x);
    }
    sort(vz.rbegin(), vz.rend());
    sort(vo.rbegin(), vo.rend());
    ll ans = 0;
    int szz = vz.size();
    int szo = vo.size();
    if (szz > szo)
    {
        int i = 0;
        for (; i < szo; i++)
        {
            ans += (2ll * (vz[i] + vo[i]));
        }
        for (int j = i; j < szz; j++)
        {
            ans += vz[j];
        }
    }
    else if (szz < szo)
    {
        int i = 0;
        for (; i < szz; i++)
        {
            ans += (2ll * (vz[i] + vo[i]));
        }
        for (int j = i; j < szo; j++)
        {
            ans += vo[j];
        }
    }
    else
    {
        int i = 0;
        for (; i < szz - 1; i++)
        {
            ans += (2ll * (vz[i] + vo[i]));
        }
        if (vz[szz - 1] > vo[szo - 1])
        {
            ans += (2 * vz[szz - 1]);
            ans += vo[szo - 1];
        }
        else
        {
            ans += (2 * vo[szz - 1]);
            ans += vz[szo - 1];
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
