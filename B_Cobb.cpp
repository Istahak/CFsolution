#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, i * (i - 1) - k * (v[i] | v[i - 1]));
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
