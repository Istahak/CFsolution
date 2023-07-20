#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int x = 0;
    while ((x + 1) * (x + 2) / 2 <= k)
    {
        x += 1;
    }
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i < x)
            v[i] = 2;
        else if (i == x)
        {

            v[i] = -2 * x - 1 + 2 * (k - x * (x + 1) / 2);
        }
        else
            v[i] = -1000;
    }
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
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
