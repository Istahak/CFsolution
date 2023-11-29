#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
void sieve(ll maximum)
{
    maximum = max(maximum, 1ll);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
    for (int p = 2; p <= maximum; p++)
    {
        if (prime[p])
        {
            smallest_factor[p] = p;
            primes.push_back(p);
            for (int64_t i = (int64_t)(p)*p; i <= maximum; i += p)
            {
                if (prime[i])
                {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
            }
        }
    }
}
vector<pair<int64_t, int>> prime_factorize(int64_t n)
{
    vector<pair<int64_t, int>> result;
    for (auto i : primes)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt)
        {
            result.emplace_back(i, cnt);
        }
    }
    if (n > 1)
        result.emplace_back(n, 1);
    return result;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    set<int> st;
    vector<int> vv(1e5 + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto p = prime_factorize(x);
        int cnt = 0;
        for (auto [xx, y] : p)
        {
            cnt += y;
            vv[xx] = max(vv[xx], y);
        }
        // cout << cnt << '\n';
        // ans += cnt;
    }
    for (int i = 0; i < 1e5 + 1; i++)
    {
        if (vv[i])
            ans += vv[i];
    }
    cout << (ans % 2 == 0 ? "Bob" : "Alice") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    sieve(sqrtl(1e5 + 10));
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}