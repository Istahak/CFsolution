#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> J(n);
    for (auto &x : J)
        cin >> x;
    vector<ll> G(m);
    for (auto &x : G)
        cin >> x;

    ll ans = accumulate(J.begin(), J.end(), 0LL);
    ll mxg = *max_element(G.begin(), G.end());
    ll mxj = *max_element(J.begin(), J.end());
    ll mig = *min_element(G.begin(), G.end());

    ll mij = *min_element(J.begin(), J.end());
    if (mij <= mig)
    {
        if (k % 2 == 0)
        {
            ans = ans + min(mxj, mxg) - mxj;
        }
        else
        {
            ans = ans - mij + mxg;
        }
    }
    else if (mij >= mxg)
    {
        if (k % 2 == 0)
        {
            ans = ans - mxj + mig;
        }
    }
    else
    {
        if (k % 2 == 0)
        {
            ans = ans + min(mxj, mxg) - mxg;
        }
        else
        {
            ans = ans - mij + mxg;
        }
    }
    cout << ans << '\n';
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