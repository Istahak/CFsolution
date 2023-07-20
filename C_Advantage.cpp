#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), vf(n);
    for (auto &i : v)
        cin >> i;

    vf = v;
    sort(vf.rbegin(), vf.rend());
    int mx = vf[0], mx2 = vf[1];

    for (int i = 0; i < n; i++)
    {
        if (mx == v[i])
        {
            cout << v[i] - mx2 << ' ';
        }
        else
        {
            cout << v[i] - mx << ' ';
        }
    }
    cout << endl;
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