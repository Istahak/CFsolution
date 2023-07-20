#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), ans;
    map<int, int> mp;
    for (auto &i : v)
        cin >> i, mp[i]++;
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] == 1)
        {
            ans.push_back(v[i]);
            mp.erase(v[i]);
        }
        else
            mp[v[i]]--;
    }
    cout << ans.size() << endl;
    for (auto ans : ans)
        cout << ans << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //  cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}