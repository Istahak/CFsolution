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
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int mi = v[i];
        int pos = 0;
        for (int j = i; j < n; j++)
        {
            if (mi > v[j])
            {
                mi = v[j];
                pos = j;
            }
        }
        if (v[i] == mi)
            continue;
        for (int j = pos; j > i; j--)
        {
            v[j] = v[j - 1];
        }
        v[i] = mi;
        
        ans.emplace_back(i + 1, pos + 1, pos - i);
    }
   
    cout << ans.size() << '\n';
    for (auto [l, r, d] : ans)
        cout << l << ' ' << r << ' ' << d << '\n';
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