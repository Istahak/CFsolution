#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int M = 1e9 + 7, N = 200000 + 5;
ll fact[N], invfact[N];
ll bigmod(ll a, ll b)
{
    a %= M;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
void factorialcul()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = ((fact[i - 1] % M) * (i % M)) % M;
    }
    invfact[N - 1] = bigmod(fact[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
    {
        invfact[i] = ((invfact[i + 1] % M) * (i + 1)) % M;
    }
}
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0ll;
    ll res = fact[n] % M;
    res = res * (invfact[n - r] % M);
    res %= M;
    res = res * (invfact[r] % M);
    res %= M;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorialcul();
    int n, k;
    cin >> n >> k;
    map<ll, ll> active;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        active[l]++;
        active[r + 1]--;
    }
    vector<int> v;
    for (auto x : active)
        v.push_back(x.first);
    ll ans = 0, currentactive = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        currentactive += active[v[i]];
        ll sz = v[i + 1] - v[i];
        if (currentactive >= k)
        {
            ans = (ans % M + (ncr(currentactive, k) % M) * (sz % M)) % M;
        }
    }
    cout << ans << endl;

    return 0;
}