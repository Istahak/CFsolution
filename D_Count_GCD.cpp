#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
long long mulmod(long long a, long long b)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}
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
ll get(ll extra, ll total)
{
    auto p = prime_factorize(extra);
    int n = p.size();
    ll res = total;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        ll cur = 1;
        for (int i = 0; i < n; i++)
        {
            if (((1 << i) & mask))
            {
                cur *= p[i].first;
            }
        }

        if (__builtin_popcount(mask) & 1)
            res -= (total / cur);
        else
            res += (total / cur);
    }
    return res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] % v[i])
        {
            cout << 0 << '\n';
            return;
        }
        if (v[i] == v[i - 1])
        {
            ans = mulmod(ans, m / v[i]);
            continue;
        }
        else
        {
            ll extra = v[i - 1] / v[i];
            ll total = m / v[i];
            ans = mulmod(ans, get(extra, total));
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
    sieve(sqrtl(1e9));
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}