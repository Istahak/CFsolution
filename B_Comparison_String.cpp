#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int mx = INT_MIN;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '>')
            x++, y = 0;
        if (s[i] == '<')
            x = 0, y++;
        mx = max(x, mx);
        mx = max(y, mx);
    }
    cout << mx + 1 << endl;
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