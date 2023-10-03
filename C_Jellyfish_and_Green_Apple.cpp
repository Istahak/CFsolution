#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m;
    cin >> n >> m;
    n %= m;
    if (n == 0)
    {
        cout << 0 << '\n';
        return;
    }
    ll lc = lcm(n, m);

    // lc *= 2;
    bitset<32> bs(lc);
    int k = log2(lc);
    bool ok = false;
    for (int i = k; i >= 0; i--)
    {
        if (bs[i] == 1 and ok)
        {
            cout << -1 << '\n';
            return;
        }
        if (bs[i] == 0)
            ok = true;
    }
    cout << bitset<8>(lc) << '\n';
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