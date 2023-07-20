#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    auto comp = [&](ll x, ll y)
    {
        int cntx2 = 0, cntx3 = 0, cnty2 = 0, cnty3 = 0;
        while (x % 3 == 0)
            cntx3++, x /= 3;
        while (x % 2 == 0)
            cntx2++, x /= 2;
        while (y % 3 == 0)
            cnty3++, y /= 3;
        while (y % 2 == 0)
            cnty2++, y /= 2;
        if (cntx3 == cnty3)
            return cntx2 < cnty2;
        else
            return cntx3 > cnty3;
    };
    sort(v.begin(), v.end(), comp);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}