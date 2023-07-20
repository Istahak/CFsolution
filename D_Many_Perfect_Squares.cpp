#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> element(n);
    for (auto &i : element)
        cin >> i;
    auto divisor = [&](ll x)
    {
        vector<ll> v;
        for (ll i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                v.push_back(i);
                if ((x / i) != i)
                {
                    v.push_back(x / i);
                }
            }
        }
        return v;
    };
    auto calculatesqureness = [&](ll x)
    {
        int cnt = 0;
        for (auto e : element)
        {
            ll y = e + x;
            ll f = sqrtl(y);
            if (f * f == y)
                cnt++;
        }
        return cnt;
    };
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll dif = element[j] - element[i];
            auto d = divisor(dif);
            for (auto f : d)
            {
                ll s = dif / f;
                ll k = (s + f) / 2;
                ll x = k * k - element[j];
                if (x < 0)
                    continue;
                auto curans = calculatesqureness(x);
                ans = max(ans, curans);
            }
        }
    }
    cout << ans << endl;
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