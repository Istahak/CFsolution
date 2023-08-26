#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v[31];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bitset<31> bs(x);
        for (int j = 30; j >= 0; j--)
        {
            if (bs[j])
            {
                v[j].push_back(x);
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        if (v[i].size())
        {
            ans = max(ans, (int)v[i].size());
        }
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