#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<string, int> mp;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string X;
        X.push_back(s[i]);
        X.push_back(s[i + 1]);
        if (mp[X])
            continue;
        mp[X]++;
        ans++;
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