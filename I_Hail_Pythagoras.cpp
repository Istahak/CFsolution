#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
void sieve(ll maximum = sqrt(N))
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
vector<int64_t> get_factors(const vector<pair<int64_t, int>> &pf)
{
    vector<int64_t> res;

    function<void(int64_t, int)> dfs = [&](int64_t yet, int i)
    {
        if (i == (int)pf.size())
        {
            res.push_back(yet);
            return;
        }
        for (int x = 0; x <= pf[i].second; x++)
        {
            dfs(yet, i + 1);
            yet *= pf[i].first;
        }
    };
    dfs(1, 0);
    sort(res.begin(), res.end());
    return res;
}
vector<int64_t> get_factors(int64_t x)
{
    return get_factors(prime_factorize(x));
}
vector<pair<int64_t, int>> combine(const vector<pair<int64_t, int>> &pf1, const vector<pair<int64_t, int>> &pf2)
{
    vector<pair<int64_t, int>> res;
    int n = pf1.size(), m = pf2.size();
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (i == n)
        {
            res.push_back(pf2[j++]);
            continue;
        }
        if (j == m)
        {
            res.push_back(pf1[i++]);
            continue;
        }
        if (pf1[i].first == pf2[j].first)
        {
            res.push_back({pf1[i].first, pf1[i].second + pf2[j].second});
            i++;
            j++;
        }
        else
        {
            res.push_back(pf1[i].first < pf2[j].first ? pf1[i++] : pf2[j++]);
        }
    }
    return res;
}
ll ans[N + 2];
void init()
{
    for (int64_t a = 2; a < N; a++)
    {
        for (auto divisor : get_factors(a))
        {
            ll x = divisor;
            ll y = (a * 1ll * a) / divisor;
            if (x % 2 != y % 2)
                continue;
            ll c = (x + y) >> 1;
            ll b = (x - y) >> 1;
            if (a <= b && b <= c)
                ans[a]++;
        }
        ans[a] += ans[a - 1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    sieve();
    init();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}