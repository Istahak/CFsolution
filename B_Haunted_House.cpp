#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    vector<ll> ans;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            ans.push_back(cnt);
        else
        {
            cnt++;
        }
    }
    int sz = ans.size();
    for (int i = 1; i < sz; i++)
    {
        ans[i] += ans[i - 1];
    }
    while (ans.size() < n)
        ans.push_back(-1);
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
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