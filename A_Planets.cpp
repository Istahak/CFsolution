#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    map<int, int> mp;
    for (auto &i : v)
    {
        cin >> i;
        mp[i]++;
    }
    int ans = 0;
    for (auto i : mp)
    {
        if (i.second > c)
            ans += c;
        else
            ans += i.second;
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
