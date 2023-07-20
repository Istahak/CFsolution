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
    sort(v.begin(), v.end());
    if (v.back() == 0)
    {
        cout << v.back() << endl;
        return;
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
    {
        if (v[n - i] > i and v[n - i - 1] <= i)
            ans = i;
    }
    cout << ans << endl;
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