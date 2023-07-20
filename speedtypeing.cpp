#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    string s, r;
    cin >> s >> r;
    int sz = s.size();
    int rz = r.size();
    int i = 0, j = 0;
    while (i < sz && j < rz)
    {
        if (s[i] == r[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if (i == sz)
        cout << rz - sz << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
