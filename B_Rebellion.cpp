#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (auto &i : v)
    {
        cin >> i;
        mp[i]++;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!mp[1])
            break;
        if (v[i] == 0)
        {
            if (mp[1])
            {
                mp[1]--;
                ans++;
            }
        }
        else
        {
            mp[1]--;
        }
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
