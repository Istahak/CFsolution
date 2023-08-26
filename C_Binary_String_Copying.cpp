#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2e6 + 9;

int power(long long n, long long k, const int mod)
{
    int ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n += mod;
    while (k)
    {
        if (k & 1)
            ans = (long long)ans * n % mod;
        n = (long long)n * n % mod;
        k >>= 1;
    }
    return ans;
}
const int MOD1 = 1000000007, MOD2 = 1000000009;
const int p1 = 5, p2 = 7;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }
}
vector<pair<int, int>> hs0, hs1;
void build()
{
    hs0.push_back({0, 0});

    for (int i = 0; i < N; i++)
    {
        pair<int, int> p;
        p.first = (hs0[i].first + 1LL * pw[i].first * (1) % MOD1) % MOD1;
        p.second = (hs0[i].second + 1LL * pw[i].second * (1) % MOD2) % MOD2;
        hs0.push_back(p);
    }
    hs1.push_back({0, 0});
    for (int i = 0; i < N; i++)
    {
        pair<int, int> p;
        p.first = (hs1[i].first + 1LL * pw[i].first * (2) % MOD1) % MOD1;
        p.second = (hs1[i].second + 1LL * pw[i].second * (2) % MOD2) % MOD2;
        hs1.push_back(p);
    }
}
struct Hashing
{
    int n;
    string s;                  // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(string _s)
    {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * (s[i] - '0' + 1) % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * (s[i] - '0' + 1) % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r)
    { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash()
    {
        return get_hash(1, n);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> one(n + 2, 0), zero(n + 2, 0);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            one[i + 1] = 1;

        else
            zero[i + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        one[i + 1] += one[i];
        zero[i + 1] += zero[i];
    }
    Hashing st(s);
    set<pair<int, int>> ss;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int cnt1 = one[r] - one[l - 1];
        int cnt0 = zero[r] - zero[l - 1];
        pair<int, int> hhh = {0, 0};
        if (l > 1)
            hhh = st.get_hash(1, l - 1);
        auto [h1, h11] = hhh;
        auto [h2, h22] = hs0[cnt0];
        auto [h3, h33] = hs1[cnt1];

        pair<int, int> hhhh = {0, 0};
        if (n > r)
            hhhh = st.get_hash(r + 1, n);
        auto [h4, h44] = hhhh;
        h1 = (h1 + (h2 * pw[l - 1].first) % MOD1) % MOD1;
        h1 = (h1 + (h3 * pw[l + cnt0 - 1].first) % MOD1) % MOD1;
        h1 = (h1 + (h4 * pw[r].first) % MOD1) % MOD1;

        h11 = (h11 + (h22 * pw[l - 1].second) % MOD2) % MOD2;
        h11 = (h11 + (h33 * pw[l + cnt0 - 1].second) % MOD2) % MOD2;
        h11 = (h11 + (h44 * pw[r].second) % MOD2) % MOD2;
        ss.insert({h1, h11});
    }
    cout << ss.size() << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    prec();
    build();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}