#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> index;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            index.push_back(i);
    }
    int sz = index.size();
    if (sz & 1)
    {
        cout << -1 << endl;
        return;
    }
    if (sz == 2 && index[0] == index[1] - 1)
    {
        cout << min(x, 2ll * y) << endl;
        return;
    }
    sz >>= 1;
    cout << sz * y * 1ll << endl;
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
