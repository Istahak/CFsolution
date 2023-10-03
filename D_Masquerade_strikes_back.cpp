#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e7 + 1;
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
    // sort(res.begin(), res.end());
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
void test_case()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        auto &[x, y] = v[i];
        cin >> x;
        y = i;
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n;)
    {
        int val = v[i].first;
        vector<int> idx;
        idx.push_back(v[i].second);
        while (i < n - 1 and v[i].first == v[i + 1].first)
        {
            idx.push_back(v[i + 1].second);
            i += 1;
        }
        i += 1;
        auto di = get_factors(val);
        if ((int)di.size() < (int)idx.size())
        {
            cout << "NO" << '\n';
            return;
        }
        int k = 0;
        for (auto x : idx)
        {
            ans[x] = {di[k], val / di[k]};
            k += 1;
        }
    }
    cout << "YES" <<'\n';
    for (auto [a, b] : ans)
        cout << a << ' ' << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //   cin >> t;
    sieve((ll)sqrt(N));
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}