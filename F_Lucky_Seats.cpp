#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 2;
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 and b == 0)
    {
        cout << 1 << '\n'
             << 0 << '\n';
        return;
    }
    int cnt = __builtin_popcount(a);
    if (cnt == 1)
    {
        if (b == a)
        {
            cout << 2 << '\n';
            cout << 0 << ' ' << a << '\n';
            return;
        }
    }
    // 5 -> 101
    // 0 -> 000
    // 2 -> 010
    set<int> ans;
    for (int mask = 0; mask <= a; mask++)
    {

        bool ok = true;
        for (int i = 0; i < 15; i++)
        {
            if ((a & (1 << i)) == 0)
            {
                if ((mask & (1 << i)) > 0)
                    ok = false;
            }
        }
        if (ok)
            ans.insert(mask);
    }
    if (b != 0)
        ans.erase(b);
    int orr = 0;
    int xoor = 0;
    for (auto x : ans)
        orr |= x, xoor ^= x;
    if (orr == a and xoor == b)
    {

        cout << ans.size() << '\n';
        for (auto x : ans)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
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