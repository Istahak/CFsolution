#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int mx = *max_element(v.begin(), v.end());
    int mi = *min_element(v.begin(), v.end());
    int ans = INT_MIN;
    ans = max(ans, v[n - 1] - mi);
    ans = max(ans, mx - v[0]);
    ans = max(ans, v[n - 1] - v[0]);
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, v[i] - v[i + 1]);
    }
    cout << ans << endl;
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