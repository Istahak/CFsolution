#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &i : v)
        cin >> i;
    int mi = *min_element(v.begin(), v.end());
    if (mi & 1)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] & 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}