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

template <class T>
class BIT
{
public:
    int n;
    vector<T> f;
    BIT(int n) : n(n)
    {
        f.resize(n + 1, (T)0);
    }
    BIT(const vector<T> &a)
    { // O(n)
        n = a.size();
        f.assign(n + 1, (T)0);
        for (int i = 1; i <= n; i++)
        {
            f[i] += a[i - 1];
            if (i + (i & -i) <= n)
            {
                f[i + (i & -i)] += f[i];
            }
        }
    }
    void update(int p, T v)
    {
        while (p <= n)
            f[p] += v, p += p & -p;
    }
    T pref(int p)
    {
        T ret = 0;
        while (p)
            ret += f[p], p -= p & -p;
        return ret;
    }
    T range(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    BIT<ll> bt(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        if (prime[x])
        {
            bt.update(i, 1);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << bt.pref(i) << '\n';
    // }
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int id;
            cin >> id;
            ll sum = bt.pref(id);
            ll l = 0, r = n;
            ll ans = 0;
            while (l <= r)
            {
                ll m = (l + r) / 2;
                ll su = bt.pref(m);
                if (su <= sum)
                {
                    ans = m;
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            sum = max(sum - 1, 0LL);
            // cout << ans << '\n';
            l = 0, r = n;
            ll ans1 = 0;
            while (l <= r)
            {
                ll m = (l + r) / 2;
                ll su = bt.pref(m);
                if (su <= sum)
                {
                    ans1 = m;
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            cout << ans - ans1 - 1 << '\n';
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (prime[v[x]])
            {
                bt.update(x, -1);
            }
            v[x] = y;
            if (prime[y])
            {
                bt.update(x, 1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(N);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}