#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C')
        {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}