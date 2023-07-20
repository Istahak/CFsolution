#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> primes;
void sive()
{
    int n = sqrt(1e12 + 2);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i * 1ll <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}
vector<pair<ll, int>> getprimefactor(ll g)
{
    vector<pair<ll, int>> ans;
    for (auto p : primes)
    {
        int cnt = 0;
        while (g % p == 0)
        {
            g /= p;
            cnt++;
        }
        if (cnt)
        {
            ans.push_back({p, cnt});
        }
    }
    if (g > 1)
    {
        ans.push_back({g, 1});
    }
    return ans;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll g = __gcd(a, b);
    auto ans = getprimefactor(g);
    sort(ans.begin(), ans.end());
    for (auto [x, y] : ans)
        cout << x << ' ' << y << endl;
    cout << 0 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    sive();
    while (tt--)
        solve();

    return 0;
}