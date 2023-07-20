#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    auto p = [&](ll a, int b)
    {
        int cnt = 0;
        while (a % b == 0)
            a /= b, cnt++;
        return cnt;
    };
    int n2 = p(n, 2);
    int n5 = p(n, 5);

    ll f = 1;
    while (n2 < n5 and (f * 2) <= k)
        f *= 2, n2++;
    while (n5 < n2 and (f * 5) <= k)
        f *= 5, n5++;
    while ((f * 10) <= k)
        f *= 10;
    f = (k / f) * f;
    cout << n * f << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}