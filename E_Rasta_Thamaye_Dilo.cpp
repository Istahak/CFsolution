#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 10;
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
ll prefix[N];
void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 0 << '\n';
        return;
    }
    if (n == 3)
    {
        cout << 1 << '\n';
        return;
    }
    cout << prefix[n] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    sieve(N);
    for (auto p : primes)
    {
        prefix[p]++;
        p *= 2;
        if (p <= 1e7)
        {
            prefix[p]--;
        }
    }
    for (int i = 1; i < N; i++)
        prefix[i] += prefix[i - 1];
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}