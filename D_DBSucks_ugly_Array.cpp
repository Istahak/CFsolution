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
    int n, m;
    cin >> n >> m;
    vector<bool> v(m + 1, true);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            continue;
        auto pp = prime_factorize(x);
        for (auto [p, c] : pp)
        {
            x = p;
            if (p <= m)
            {
                if (v[x])
                {
                    for (int j = x; j <= m; j += x)
                        v[j] = false;
                }
            }
        }
    }
    cout << accumulate(v.begin(), v.end(), -1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    sieve(sqrt(1e6));
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}