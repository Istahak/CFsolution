#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 10;
ll phi[N];
void totient()
{
    for (int i = 1; i < N; i++)
        phi[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    for (int i = 1; i < N; i++)
        phi[i] += phi[i - 1];
}
void solve()
{
    ll n, p;
    cin >> n >> p;
    ll l = 1, r = n, ans = -1;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (phi[n / m] >= p)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
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
    totient();
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}