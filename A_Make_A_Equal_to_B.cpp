#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), v1(n);
    int one = 0;
    for (auto &i : v)
    {
        cin >> i;
        if (i & 1)
            one++;
    }
    for (auto &i : v1)
    {
        cin >> i;
        if (i & 1)
            one--;
    }
    if (one < 0)
        one = -one;
    int ans = one;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != v1[i])
        {
            if (one)
            {
                one--;
                continue;
            }
            else
            {
                ok = true;
            }
        }
    }
    if (ok)
        ans++;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
