#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    vector<int> v(6);
    for (auto &i : v)
        cin >> i;
    bool ok1 = false, ok2 = false;
    if (v[0] == v[2] || v[2] == v[4] || v[0] == v[4])
    {
        ok1 = true;
    }
    if (v[1] == v[3] || v[3] == v[5] || v[1] == v[5])
    {
        ok2 = true;
    }
    cout << ((ok1 && ok2) ? "NO" : "YES") << endl;
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