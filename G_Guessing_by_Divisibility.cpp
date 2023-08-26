#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 1;
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
string query(int x)
{
    cout << "? " << x << endl;
    string s;
    cin >> s;
    return s;
}
void solve()
{
    vector<int> p1, p2;
    for (auto x : primes)
        if (x <= 5000)
            p1.push_back(x);
        else
            p2.push_back(x);
    set<int> st;
    for (auto x : primes)
    {
        if (query(x) == "Yes")
            st.insert(x);
    }
    // if (st.empty())
    // {
    //     for (auto x : p2)
    //     {
    //         if (query(x) == "Yes")
    //         {
    //             cout << "! " << x << endl;
    //             return;
    //         }
    //     }
    // }
    int ans = 1;
    for (int i = 1; i <= 1e4; i++)
    {
        auto pf = prime_factorize(i);
        if (pf.size() == st.size())
        {
            bool ok = true;
            for (auto [x, y] : pf)
            {
                if (!st.count(x))
                    ok = false;
            }
            if (ok)
            {
                if (query(i) == "Yes")
                    ans = i;
            }
        }
    }
    cout << "! " << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    sieve();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}