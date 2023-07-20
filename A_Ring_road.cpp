#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<bool> v(n + 1, false), u(n + 1, false);
    ll sum1 = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (v[x] || u[y])
        {
            sum1 += w;
            v[y] = u[x] = true;
        }
        else
            v[x] = u[y] = true;
        sum += w;
    }
    cout << min(sum1, sum - sum1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {

        solve();
    }

    return 0;
}