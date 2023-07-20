#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);

    for (auto &i : v)
        cin >> i;
    sort(v.begin() + 1, v.end());
    for (int i = 1; i < n; i++)
    {
        if (v[0] >= v[i])
            continue;
        v[0] = (v[0] + v[i] + 1) / 2;
    }

    cout << v[0] << endl;
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