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
    int n, q;
    cin >> n >> q;
    sieve(sqrtl(n));
    multiset<int> st[n + 1];
    vector<int> vis(n + 1, false);
    while (q--)
    {
        char ty;
        int x;
        cin >> ty >> x;
        if (ty == '+')
        {
            if (vis[x])
            {
                cout << "Already on\n";
                continue;
            }
            auto vv = prime_factorize(x);
            int curans = -1;
            for (auto [p, c] : vv)
            {
                if (st[p].size() == 0)
                    continue;
                else
                {
                    curans = (*st[p].begin());
                    break;
                }
            }
            if (curans != -1)
            {
                cout << "Conflict with " << curans << '\n';
            }
            else
            {
                vis[x] = true;
                for (auto [p, c] : vv)
                    st[p].insert(x);
                cout << "Success\n";
            }
        }
        else
        {
            if (!vis[x])
            {
                cout << "Already off\n";
                continue;
            }
            auto vv = prime_factorize(x);
            for (auto [p, c] : vv)
            {
                if (st[p].count(x))
                    st[p].erase(x);
            }
            cout << "Success\n";
            vis[x] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}