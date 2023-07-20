#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 2 * 1e5 + 10;
ll n, k;
vector<int> v(N);
ll extra(int i)
{
    if (i >= n || i < 1)
        return 0;
    if (v[i] != v[i + 1])
        return 1LL * i * (n - i);
    else
        return 0;
}
void solve()
{
    cin >> n >> k;
    ll ans = n * (n + 1) * 1ll;
    ans /= 2;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++)
    {
        ans += extra(i);
    }
    while (k--)
    {
        int i, x;
        cin >> i >> x;
        ans -= extra(i);
        ans -= extra(i - 1);
        v[i] = x;
        ans += extra(i);
        ans += extra(i - 1);
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
