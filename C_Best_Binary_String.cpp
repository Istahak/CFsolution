#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    string ans;
    bool ok1 = true, ok2 = false;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (ok2)
                ans.push_back('1');
            else
                ans.push_back('0');
        }
        if (s[i] == '1')
        {
            ans.push_back(s[i]);
            ok2 = true;
        }
        if (s[i] == '0')
        {
            ans.push_back(s[i]);
            ok2 = false;
            ok1 = false;
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