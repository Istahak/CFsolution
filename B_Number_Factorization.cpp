#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    map<int, int> mp;
    vector<int> prime;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            prime.push_back(i);
        while (n % i == 0)
        {
            n /= i;
            mp[i]++;
        }
    }
    if (n > 1)
    {
        mp[n]++;
        prime.push_back(n);
    }
    sort(prime.begin(), prime.end());
    bool ok = true;
    ll ans = 0;
    while (ok)
    {
        ll ans1 = 1;
        ok = false;
        for (auto p : prime)
        {
            if (mp[p])
            {
                ans1 *= p;
                mp[p]--;
                ok = true;
            }
        }
        if(ok)
        ans += ans1;
    }
    // for (auto [x, y] : mp)
    //     cout << x << ' ' << y << endl;
    cout << ans << endl;
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