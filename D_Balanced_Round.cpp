#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    int ans = INT_MIN;
    for (int i = 0; i < n;)
    {
        int cnt = 1;
        while (i < n - 1 and (v[i + 1] - v[i]) <= k)
            cnt++, i++;
        i++;
        ans = max(ans, cnt);
    }
    cout << n - ans << endl;
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