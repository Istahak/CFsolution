#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    // cout << s << endl;
    int n = s.size();
    int cc = 0;
    int p = -1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] - '0' >= 5)
        {
            cc = 1;
            p = i;
        }
        else if (s[i] - '0' + cc >= 5)
        {
            p = i;
        }
        else if (cc > 0)
        {
            s[i] = s[i] + cc;
            cc = 0;
        }
    }
    // cout << s << endl;
    for (int i = p; i < s.size(); i++)
    {
        s[i] = '0';
    }
    if (cc and p == 0)
    {
        cout << 1 << s << endl;
        return;
    }
   
        cout << s << endl;
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