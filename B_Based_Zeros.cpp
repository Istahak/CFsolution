#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int base(ll n, int b)
{
    int cnt = 0;
    while (n)
    {
        if (n % b == 0)
            cnt++;
        n /= b;
    }
    return cnt;
}
vector<ll> specialNumbers = {16760831, 6143, 14335, 262079, 262111, 524031, 524285};
vector<bool> mem(7, false);
vector<vector<ll>> ans(7);
void solve()
{
    ll n;
    cin >> n;
    for (int i = 0; i < 7; i++)
    {
        if (specialNumbers[i] == n)
        {
            if (mem[i] == false)
            {
                vector<ll> v;
                for (ll i = 2; i <= n; i++)
                {
                    if (base(n, i) == 1)
                    {
                        v.push_back(i);
                    }
                }
                mem[i] = true;
                ans[i] = v;
            }

            cout << 1 << ' ' << ans[i].size() << '\n';
            for (auto x : ans[i])
            {
                cout << x << ' ';
            }
            cout << '\n';

            return;
        }
    }
    int mx = base(n, 2);
    for (ll i = 3; i <= 5000; i++)
    {
        mx = max(mx, base(n, i));
    }
    vector<ll> aa;
    for (ll i = 2; i <= 5000; i++)
    {
        if (mx == base(n, i))
        {
            aa.push_back(i);
        }
    }
    cout << mx << ' ' << aa.size() << '\n';
    for (auto &a : aa)
        cout << a << ' ';
    cout << '\n';
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