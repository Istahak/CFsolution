#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(m);
    for (auto &i : v)
        cin >> i;
    ll cnt = 0;
    ll block = n / k;
    for (auto i : v)
    {
        if (i > block)
        {
            if (i <= (block + 1))
                cnt++;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << (cnt > n % k ? "NO" : "YES") << endl;
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