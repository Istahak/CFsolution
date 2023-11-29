#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int N = 1e6 + 10;
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
void sieve(ll maximum = N)
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

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    int sz = primes.size();
    for (int i = 0; i < sz; i++)
    {
        ll a = primes[i];
        ll overflow = a * a * a * a * a;
        if (overflow > n)
            break;
        for (int j = i + 1; j < sz; j++)
        {
            ll b = primes[j];
            overflow = a * a * b * b * b;
            if (overflow > n)
                break;
            ll c = n / (a * a * b);
            c = sqrtl(c);
            ans += upper_bound(primes.begin() + j + 1, primes.end(), c) - (primes.begin() + j + 1);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}