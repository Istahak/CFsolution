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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        v[i] = -v[i];
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 2 == 0)
            ans++;
        v[i] = -v[i];
    }
    cout << ans << '\n';
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