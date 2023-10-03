#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
void sieve(ll maximum = 1000)
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
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << 3 << endl;
        cout << "3 2 1" << endl;
        return;
    }
    vector<int> ans;
    ans.push_back(n);
    while (n != 1)
    {
        if (n & 1)
        {
            n -= 1;
            ans.push_back(n);
        }
        else
        {
            ll cur = 1;
            ll cc = n;
            while (cc % 2 == 0)
                cur *= 2, cc /= 2;
            if (n == cur)
                break;
            n -= cur;
            ans.push_back(n);
        }
    }
    while (n != 2)
    {
        n /= 2;
        ans.push_back(n);
    }
    ans.push_back(1);
    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    sieve();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}