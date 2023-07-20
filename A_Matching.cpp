#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), '?');
    if (s[0] == '0')
    {
        cout << 0 << endl;
        return;
    }
    if (x == 0)
    {
        if (s[0] == '0')
            cout << x << endl;
        else
            cout << 1 << endl;
        return;
    }
    if (s[0] == '?')
    {
        cout << int(9 * pow(10, x - 1)) << endl;
    }
    else
        cout << int(pow(10, x)) << endl;
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