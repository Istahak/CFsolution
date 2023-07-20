#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M = 998244353, N = 3e5 + 10;
ll factor[N];
ll inversemod(ll a, ll b)
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
ll ncr(ll n, ll r)
{
    ll res = (factor[n] % M) * (inversemod(factor[r], M - 2) % M) % M;
    res = (res % M) * (inversemod(factor[n - r], M - 2) % M) % M;
    return res;
}
void factorialcul()
{
    factor[0] = 1;
    for (int i = 1; i < N; i++)
    {
        factor[i] = ((factor[i - 1] % M) * (i % M)) % M;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorialcul();
    int n, k;
    cin >> n >> k;
    vector<int> start(n + 1), end(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> start[i] >> end[i];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    ll lighton = 0, ans = 0;
    int i = 1, j = 1;
    while (i <= n and j <= n)
    {
        if (start[i] <= end[j])
        {
            if (lighton >= k - 1)
            {
                ans = (ans % M + ncr(lighton, k - 1)) % M;
            }
            lighton++, i++;
        }
        else
        {
            lighton--, j++;
        }
    }
    cout << ans << endl;
    return 0;
}