#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
const int N = 1e7 + 1;
vector<int> spf(N, 0);
void sive()
{
    for (int i = 2; i <= N; i++)
    {
        if (!spf[i])
        {
            for (int j = i; j <= N; j += i)
                spf[j] = i;
        }
    }
}
void solve()
{
    int x, y;
    cin >> x >> y;
    int d = y - x;
    if (d == 1)
    {
        cout << -1 << endl;
        return;
    }
    int ans = INT_MAX;
    while (d > 1)
    {
        int p = spf[d];
        int X = (x + p - 1) / p * p;
        ans = min(ans, X - x);
        while (d % p == 0)
            d /= p;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    sive();
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}