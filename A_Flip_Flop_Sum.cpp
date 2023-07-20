#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        // if (v[i] == 1)
        ans += v[i];
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == -1 && v[i + 1] == -1)
        {
            ans += 4;
            ok = false;
            break;
        }
    }
    if (ok)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] == -1)
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
        ans -= 4;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}