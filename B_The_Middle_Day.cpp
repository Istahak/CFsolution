#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int total = accumulate(v.begin(), v.end(), 0);
    total = (total + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        if (total > v[i])
            total -= v[i];
        else
        {
            cout << i + 1 << ' ' << total << endl;
            return;
        }
    }
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