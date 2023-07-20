#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (auto &i : b)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[a[i].second] = b[i];
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
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