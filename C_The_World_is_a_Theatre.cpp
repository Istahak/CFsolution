#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 31;
__uint128_t fact[N + 1];

void factorialcul()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0ll;
    __uint128_t res = fact[n];
    __uint128_t res1 = fact[r] * fact[n - r];
    res /= res1;
    ll rr = res;
    return rr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorialcul();
    int b, g, n;
    cin >> b >> g >> n;

    __uint128_t ans = 0;
    for (ll i = 1; i < n; i++)
    {
        ll curg = i;
        ll curb = n - i;
        if (curb < 4 || curb > b)
            continue;
        // cout << curg << ' ' << curb << endl;
        ans += (ncr(g, curg) * ncr(b, curb));
    }
    ll Ans = ans;
    cout << Ans << endl;
    return 0;
}