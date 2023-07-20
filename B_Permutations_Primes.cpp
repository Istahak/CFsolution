#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> smallest_factor;
vector<bool> prime;
set<int> primes;
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
            primes.insert(p);
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
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 2)
    {
        cout << 2 << ' ' << 1 << endl;
        return;
    }
    vector<int> v(n + 1);
    v[1] = 2;
    v[(n + 1) / 2] = 1;
    v[n] = 3;
    int x = 4;
    for (int i = 2; i < n; i++)
    {
        if (i == (n + 1) / 2)
        {
            continue;
        }
        else
        {
            v[i] = x++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}