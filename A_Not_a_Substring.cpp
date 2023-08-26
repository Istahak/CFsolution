#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    string ans = "", ans1 = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        ans += "()";
        ans1 += "(";
    }
    for (int i = 0; i < n; i++)
    {
        ans1 += ")";
    }
    // cout<<ans1<<endl;
    auto f = ans.find(s);
    if (f == string::npos)
    {
        cout << "YES" << endl;
        cout << ans << endl;
        return;
    }
    auto ff = ans1.find(s);
    if (ff == string::npos)
    {
        cout << "YES" << endl;
        cout << ans1 << endl;
        return;
    }
    cout << "NO" << endl;
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