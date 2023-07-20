#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const ll M = 1000003;
ll fact[1000000];
ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1 % M;
    ll x = bigmod(a, b / 2);
    x = (x * x) % M;
    if (b & 1)
        x = (x * a) % M;
    return x;
}
ll modularinverse(ll x)
{
    return bigmod(x, M - 2);
}
ll nCr(ll n, ll r)
{
    ll ans = fact[n];
    ans = ((ans % M) * (modularinverse(fact[n - r]) % M)) % M;
    ans = ((ans % M) * (modularinverse(fact[r]) % M)) % M;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    fact[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
        fact[i] = ((fact[i - 1] % M) * (i % M)) % M;
    cin >> t;
    int z=1;
    while (t--)
    {

        ll n, r;
        cin >> n >> r;
        cout << "Case "<<z<<":"<<' '<<nCr(n, r) << endl;
        z++;
    }

    return 0;
}