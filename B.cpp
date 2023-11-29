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
struct SparseTable
{
    int N, K;
    vector<vector<int>> sp;
    vector<int> lg;

    void init(int n)
    {
        N = n;
        while ((1 << K) < n)
            K++;
        sp.resize(N, vector<int>(K));
        lg.resize(N + 1);
        lg[1] = 0;
        for (int i = 2; i <= N; i++)
        {
            lg[i] = lg[i / 2] + 1;
        }
    }

    int merge(int a, int b)
    {
        return __gcd(a, b);
    }

    void build(vector<int> &a)
    {
        for (int i = 0; i < N; i++)
            sp[i][0] = a[i];
        for (int j = 1; j < K; j++)
        {
            for (int i = 0; (i + (1 << j)) <= N; i++)
            {
                sp[i][j] = merge(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int calc(int l, int r)
    {
        int j = lg[r - l + 1];
        return merge(sp[l][j], sp[r - (1 << j) + 1][j]);
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    SparseTable sp;
    sp.init(n + 5);
    int gc = 0;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sp.build(v);
    map<int, int> mp;
    // if (gc > 1)
    // {
    //     cout << 0 << '\n';
    //     return;
    // }
    int ans = 0;
    int i = 0, j = 0;
    while (i < n and j < n)
    {
        i = max(i, j);
        if (mp.size() <= k)
        {
            auto p = prime_factorize(v[i]);
            for (auto [x, y] : p)
            {
                mp[x] += y;
            }
            if (mp.size() == k)
            {
                if (sp.calc(j, i) == 1)
                {
                    int curans = i - j + 1;
                    ans = max(ans, curans);
                }
            }
            i++;
        }
        else if (mp.size() > k)
        {

            auto pp = prime_factorize(v[j]);
            for (auto [x, y] : pp)
            {
                mp[x] -= y;
                if (mp[x] == 0)
                {
                    mp.erase(x);
                }
            }
            j++;
            if (mp.size() == k)
            {
                if (sp.calc(j, i - 1) == 1)
                {
                    int curans = i - j;
                    ans = max(ans, curans);
                }
            }
        }
    }
    while (j < n)
    {
        auto pp = prime_factorize(v[j]);
        for (auto [x, y] : pp)
        {
            mp[x] -= y;
            if (mp[x] == 0)
            {
                mp.erase(x);
            }
        }
        j++;
        if (mp.size() == k)
        {
            if (sp.calc(j, n - 1) == 1)
            {
                int curans = i - j;
                ans = max(ans, curans);
            }
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
    sieve(sqrtl(N));
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}