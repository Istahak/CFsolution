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
    vector<int> ans;
    ans.push_back(v.front());
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i-1])
        {
            ans.push_back(v[i]);
        }
        ans.push_back(v[i]);
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x << " ";
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