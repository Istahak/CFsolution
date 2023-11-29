#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n), lg(n, 0);
    for (auto &x : v)
        cin >> x;

    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
        {
            lg[i] = lg[i - 1];
            // cout << lg[i] << '\n';

            continue;
        }
        if (v[i - 1] > v[i])
        {
            int cur = 0;
            ll l = v[i - 1], r = v[i];
            while (l > r)
            {
                r <<= 1;
                cur++;
            }
            lg[i] = lg[i - 1] + cur;
        }
        else
        {
            int cur = 0;
            ll l = v[i - 1], r = v[i];
            while (l <= r)
            {
                l <<= 1;
                cur++;
            }
            cur--;
            lg[i] = max(0LL, lg[i - 1] - cur);
           
        }
        // cout << lg[i] << '\n';
    }
    cout << accumulate(lg.begin(), lg.end(), 0LL) << '\n';
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