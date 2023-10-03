#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6 + 10;
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
vector<pair<int64_t, ll>> prime_factorize(int64_t n)
{
    vector<pair<int64_t, ll>> result;
    if (n == 1)
    {
        result.push_back({1, 1});
        return result;
    }
    while (n != 1)
    {
        auto p = smallest_factor[n];
        int cnt = 0;
        while (n % p == 0)
        {
            n /= p;
            cnt++;
        }
        result.push_back({p, cnt});
    }

    return result;
}

vector<pair<int64_t, ll>> combine(const vector<pair<int64_t, ll>> &pf1, const vector<pair<int64_t, ll>> &pf2)
{
    vector<pair<int64_t, ll>> res;
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
const int mod = 1e9 + 7;
__int128_t power(long long a, long long b)
{
    __int128_t x = 1;
    while (b)
    {
        if (b & 1)
            x = x * a;
        a = a * a;
        b >>= 1;
    }
    return x;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    // cout << n << ' ' << q;
    vector<ll> run;
    run.push_back(n);
    auto root = prime_factorize(n);
    auto now = root;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            ll r;
            cin >> r;
            run.push_back(r);
            auto p = prime_factorize(r);
            // for (auto [x, y] : p)
            //     cout << x << ' ' << y << '\n';
            now = combine(now, p);
            ll cnt = 1, num = 1;

            for (auto [x, y] : now)
            {
                if (x != 1)
                    cnt *= (y + 1);
            }
            for (auto x : run)
                cnt /= __gcd(x, cnt);

            if (cnt == 1)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
        else
        {
            now.clear();
            now = root;
            run.clear();
            run.push_back(n);
        }
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    sieve(N + 2);
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}