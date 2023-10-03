#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    auto getfct = [&](int n)
    {
        for (int i = 2; 1LL * i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int x = i;
                int y = n / i;
                cout << x << ' ' << x * (y - 1) << endl;
                return true;
            }
        }
        return false;
    };
    if (getfct(l))
        return;
    if (getfct(r))
        return;
    if (l != r)
        if (getfct(l + 1))
            return;
        else if (getfct(r - 1))
            return;
    cout << -1 << endl;
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